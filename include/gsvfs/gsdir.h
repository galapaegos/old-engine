#ifndef _gsdir_h_
#define _gsdir_h_

#include <gsutil/gsstring.h>
#include <gsutil/gsqueue.h>

#include <gsvfs/gsfile.h>

namespace gsvfs
{
	class gsdir
	{
	public:
		gsdir (const gsutil::gsstring &name);
		gsdir ();
		~gsdir ();

		//first thoughts on a directory header
		//  4 bytes are versioning
		//  16 bytes number of directories
		//  16 bytes number of files
		//  20 bytes for directory name (ie path)
		//  4 bytes offset to first directory
		//  4 bytes offset to first file

		void addFile (gsfile *f);
		void remFile (gsutil::gsstring &file);
		void addDir (gsdir *d);
		void remDir (gsutil::gsstring &dir);

		gsvfs::gsdir *getDir (const int &pos) { return m_vDirectories[pos]; }
		gsvfs::gsfile *getFile (const int &pos) { return m_vFiles[pos]; }
		gsvfs::gsfile *getFile (const gsutil::gsstring &file) { return findFile (file); }
		gsutil::gsqueue<gsutil::gsstring> getFileList ();
		gsutil::gsstring getName () { return m_strName; }
		unsigned int getNumFiles () { return m_vFiles.getSize (); }
		unsigned int getNumDirs () { return m_vDirectories.getSize (); }

		void setName (const gsutil::gsstring &name) { m_strName = name; }

	private:
		gsvfs::gsfile *findFile (const gsutil::gsstring &file);

		gsutil::gsqueue <gsvfs::gsdir*> m_vDirectories;
		gsutil::gsqueue <gsvfs::gsfile*> m_vFiles;

		gsutil::gsstring m_strName;
	};
};

#endif

