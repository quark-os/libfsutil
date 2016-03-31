#ifndef _FSUTIL_FILE_H
#define _FSUTIL_FILE_H

#include <string>

#include "filetype.h"

using namespace std;

class File
{
public:

	File();
	
	File(string& filename);
	
	File(Filetype type, size_t filesize, string filename, string path);
	
	Filetype getType();
	
	size_t getSize();
	
	string getFilename();
	
	string getPath();

private:

	Filetype type;
	size_t filesize;
	string filename;
	string path;

};

#endif
