#include <gsvfs/gsdir.h>

namespace gsvfs
{
	gsdir::gsdir ()
	{
	}

	gsdir::gsdir (const gsutil::gsstring &name)
	{
		m_strName = name;
	}

	gsdir::~gsdir ()
	{
		while (getNumDirs () > 0)
		{
			gsvfs::gsdir *d = getDir (0);
			m_vDirectories.erase (0);
			delete d;
		}

		while (getNumFiles () > 0)
		{
			gsvfs::gsfile *f = getFile (0);
			m_vFiles.erase (0);
			delete f;
		}
	}

	gsutil::gsqueue<gsutil::gsstring> gsdir::getFileList ()
	{
		gsutil::gsqueue<gsutil::gsstring> temp;

		for (unsigned int x = 0; x < m_vFiles.getSize (); x++)
			temp.add (m_vFiles[x]->getFileName ());

		return temp;
	}

	void gsdir::addFile (gsfile *f)
	{
		m_vFiles.add (f);
	}
	
	void gsdir::addDir (gsdir *d)
	{
		m_vDirectories.add (d);
	}

	gsvfs::gsfile *gsdir::findFile (const gsutil::gsstring &file)
	{
		gsfile *f = NULL;

		for (unsigned int x = 0; x < getNumFiles (); x++)
		{
			if (file == getFile (x)->getFileName ())
			{
				f = getFile (x);
				break;
			}
		}

		return f;
	}
};

