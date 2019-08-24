#ifndef _gsfilesystem_h_
#define _gsfilesystem_h_

#ifdef WIN32
#include <windows.h>
#endif

#include <gsutil/gsstring.h>
#include <gsutil/gsqueue.h>
#include <gsutil/gsrle.h>

#include <gsvfs/gsdir.h>

namespace gsvfs
{
	class GS gsfilesystem
	{
	public:
		gsfilesystem (const gsutil::gsstring &file="");
		~gsfilesystem ();

		void save (const gsutil::gsstring &file="");

		gsfile *loadFile (const gsutil::gsstring &path, const gsutil::gsstring &file);

		void addDir (const gsutil::gsstring &path, const gsutil::gsstring &dir);
		void removeDir (const gsutil::gsstring &path);
		void addFile (const gsutil::gsstring &path, const gsutil::gsstring &pFile);
		void removeFile (const gsutil::gsstring &path, const gsutil::gsstring &pFile);

		gsvfs::gsfile *getFile (const gsutil::gsstring &file);

		void print ();
		void printHelper (gsdir *d, int spacing = 0);

	private:
		gsdir *m_pRootDirectory;
		gsutil::gsstring m_strVFS;

		gsvfs::gsdir *findDir (const gsutil::gsstring &path);

		void openHelper (FILE *f, gsdir *d);
		void closeHelper (FILE *f, gsdir *d);

		typedef struct
		{
			char mVersion[4];
			unsigned long mReserved;
		} HeaderInfo;

		typedef struct
		{
			unsigned short nDirs;
			unsigned short nFiles;
			char mDir[40];
			unsigned long offsetDir;
			unsigned long offsetFile;
		} DirInfo;

		typedef struct
		{
			unsigned char cCompress;
			unsigned long nCompressSize;
			unsigned long nSize;
			char mFile[80];
		} FileInfo;
	};

	//vfs options header - options for the whole filesystem
	//  reserve 64 bytes
	//  4 bytes are versioning
	//
	//first thoughts on a directory header
	//  4 bytes are versioning
	//  16 bytes number of directories
	//  16 bytes number of files
	//  20 bytes for directory name (ie path)
	//  4 bytes offset to first directory
	//  4 bytes offset to first file
	//
	//first thoughts on a file header
	//  4 bytes compression method
	//  4 bytes size of file
	//  56 bytes filename
	//
	//-------------------------------------------------------------------
	//What I will do is something akin to this:
	// when you load the filesystem, scan through the whole file and find 
	//all the headers belonging to directories/files and keep these in our 
	//filesystem
	// when we save the filesystem, all the data should be written to the 
	//file already, so all we do is update the header information
	// when you 'import' a file, go to the appropriate directory and add 
	//in the header information one case to figure out:  add file to the 
	//end of the allocated storage, or repartition file every time a file 
	//is added and relocate all positions accordingly?
	// you could have a file allocate as a whole gig, and add files in 
	//accordingly...
	// I want to do the first choice, relocate all positions when a file 
	//is added
	// structure to use when storing files and directories:
	//-------------------------------------------------------------------
	//
	//This is the method to use to add/update/remove files and directories
	//-------------------------------------------------------------------
	// Basically, we have two files; the real archive, and our temporary 
	//archive.  When we need to update the real archive, we will extract
	//all directories out of the real archive and store these into the
	//temporary archive.  Then starting at the beginning, we will add
	//the archive directory into the real archive and update those archives
	//that require updating.
	// I'm sure this will be cpu intensive for now, but later on we can
	//perform a smarter update and leave some archives within the real
	//archive.
	//
};

#endif

