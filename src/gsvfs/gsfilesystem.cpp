#include <gsvfs/gsfilesystem.h>

namespace gsvfs
{
	gsfilesystem::gsfilesystem (const gsutil::gsstring &file)
	{
		m_pRootDirectory = new gsvfs::gsdir ("/");

		if (file.size () > 0)
		{
			FILE *f = fopen (file.str (), "r+b");

			if (f)
			{
				HeaderInfo hi;
				fread (&hi, sizeof (HeaderInfo), 1, f);

				openHelper (f, m_pRootDirectory);

				fclose (f);
			}

			m_strVFS = file;
		}
	}

	gsfilesystem::~gsfilesystem ()
	{
		if (m_strVFS.size () > 0)
		{
			FILE *f = fopen (m_strVFS.str (), "w+b");

			HeaderInfo hi;
			memset (&hi, 0, sizeof (HeaderInfo));
			hi.mVersion[0] = 'v';
			hi.mVersion[1] = 'f';
			hi.mVersion[2] = 's';
			hi.mVersion[3] = '1';

			fwrite (&hi, sizeof (HeaderInfo), 1, f);

			closeHelper (f, m_pRootDirectory);

			fclose (f);
		}

		if (m_pRootDirectory)
			delete m_pRootDirectory;
	}

	gsvfs::gsfile *gsfilesystem::loadFile (const gsutil::gsstring &path, const gsutil::gsstring &file)
	{
		return findDir (path)->getFile (file);
	}

	void gsfilesystem::addFile (const gsutil::gsstring &path, const gsutil::gsstring &pFile)
	{
		gsvfs::gsdir *root = findDir (path);
		
		gsvfs::gsfile *f = new gsvfs::gsfile (pFile);
		root->addFile (f);
	}

	void gsfilesystem::removeFile (const gsutil::gsstring &path, const gsutil::gsstring &pFile)
	{
		gsvfs::gsdir *root = findDir (path);
	}

	void gsfilesystem::addDir (const gsutil::gsstring &path, const gsutil::gsstring &dir)
	{
		gsvfs::gsdir *root = findDir (path);
		
		gsvfs::gsdir *d = new gsvfs::gsdir (dir);
		root->addDir (d);
	}

	void gsfilesystem::removeDir (const gsutil::gsstring &path)
	{
	}

	gsvfs::gsfile *gsfilesystem::getFile (const gsutil::gsstring &file)
	{
		gsfile *f = NULL;
		gsutil::gsstring filename = file;

		if (filename[0] == '/')
			filename.remove (0);

		gsvfs::gsdir *cur = m_pRootDirectory;
		bool found = false;

		while (!found)
		{
			int s = filename.find ('/');

			if (s == -1)
			{
				found = true;
				break;
			}

			gsutil::gsstring dirName = filename.substring (0, s);
			filename.remove (0, s + 1);

			for (unsigned int x = 0; x < cur->getNumDirs (); x++)
			{
				gsvfs::gsdir *d = cur->getDir (x);
				if (d->getName () == dirName)
				{
					cur = d;
					break;
				}
			}
		}

		f = cur->getFile (filename);

		return f;
	}

	void gsfilesystem::print ()
	{
		printf ("---------File System---------\n");
		printHelper (m_pRootDirectory);
	}

	void gsfilesystem::printHelper (gsdir *d, int spacing)
	{
		int size = 0;
		while (size < spacing)
		{
			printf (" ");
			size ++;
		}
		printf ("+%s\n", d->getName ().str ());

		for (unsigned int x = 0; x < d->getNumDirs (); x++)
			printHelper (d->getDir (x), spacing+1);

		for (unsigned int y = 0; y < d->getNumFiles (); y++)
		{
			size = 0;
			while (size < spacing + 1)
			{
				printf (" ");
				size ++;
			}
			printf ("-%s\n", d->getFile (y)->getFileName ().str ());
		}
	}

	gsdir *gsfilesystem::findDir (const gsutil::gsstring &path)
	{
		gsutil::gsstring p = path;

		//remove the first '/', which is the root
		p.remove (0);

		gsdir *current = m_pRootDirectory;

		bool found = false;
		while (!found)
		{
			if (p.size () == 0)
				break;

			int s = p.find ('/');

			gsutil::gsstring tmp;
			if (s == -1)
			{
				tmp = p;
				p.clear ();
			}
			else
			{
				tmp = p.substring (0, s);
				p.remove (0, s + 1);
			}

			for (unsigned int x = 0; x < current->getNumDirs (); x++)
			{
				gsvfs::gsdir *d = current->getDir (x);
				if (d->getName () == tmp)
				{
					current = current->getDir (x);

					if (p.size () == 0)
						found = true;

					break;
				}
			}
		}

		return current;
	}

	void gsfilesystem::openHelper (FILE *f, gsdir *d)
	{
		DirInfo di;
		fread (&di, sizeof (DirInfo), 1, f);

		d->setName (di.mDir);

		for (unsigned int x = 0; x < di.nDirs; x++)
		{
			gsvfs::gsdir *dir = new gsdir ();
			openHelper (f, dir);

			d->addDir (dir);
		}

		for (unsigned int y = 0; y < di.nFiles; y++)
		{
			gsvfs::gsfile *file = new gsvfs::gsfile;
			
			FileInfo fi;
			fread (&fi, sizeof (FileInfo), 1, f);

			unsigned char *ptr = new unsigned char[fi.nSize + 1];
			fread (ptr, fi.nSize, 1, f);

			//if (fi.cCompress == 1)
			//{
			//	unsigned char *dst = NULL;
			//	unsigned long size = gsutil::gsrle::loadRLE (ptr, fi.nCompressSize, &dst, fi.nSize);

			//	file->setData (dst);
			//	file->setSize (fi.nSize);
			//	file->setFileName (fi.mFile);
			//}
			//else
			//{
				file->setData (ptr);
				file->setSize (fi.nSize);
				file->setFileName (fi.mFile);
			//}

			d->addFile (file);
		}
	}

	void gsfilesystem::closeHelper (FILE *f, gsdir *d)
	{
		DirInfo di;
		memset (&di, 0, sizeof (DirInfo));
		strcpy (di.mDir, d->getName ().str ());
		di.nDirs = d->getNumDirs ();
		di.nFiles = d->getNumFiles ();

		fwrite (&di, sizeof (DirInfo), 1, f);

		for (unsigned int x = 0; x < d->getNumDirs (); x++)
			closeHelper (f, d->getDir (x));

		for (unsigned int y = 0; y < d->getNumFiles (); y++)
		{
			gsvfs::gsfile *file = d->getFile (y);

			FileInfo fi;
			memset (&fi, 0, sizeof (FileInfo));

			//unsigned char *dst = NULL;
			//unsigned long size = gsutil::gsrle::saveRLE (&dst, file->getData (), file->getSize ());

			strcpy (fi.mFile, file->getFileName ().str ());
			fi.nSize = file->getSize ();
			//fi.nCompressSize = size;
			fi.nCompressSize = file->getSize ();
			fi.cCompress = 1;

			fwrite (&fi, sizeof (FileInfo), 1, f);
			//fwrite (dst, size, 1, f);
			fwrite (file->getData (), file->getSize (), 1, f);
		}
	}
};

