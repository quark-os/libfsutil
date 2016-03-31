#include "file.h"
#include "workdir.h"

#include <sys/stat.h>

File::File()
{
	
}

File::File(string& filename)
{
	struct stat stats;
	int err = stat(filename.c_str(), &stats);
	
	if(S_ISDIR(stats.st_mode))
	{
		type = DIRECTORY;
	}
	else if(S_ISREG(stats.st_mode))
	{
		type = REGULAR;
	}
	else if(S_ISLNK(stats.st_mode))
	{
		type = LINK;
	}
	else
	{
		type = UNKNOWN;
	}
	filesize = stats.st_size;
	this->filename = filename.substr(filename.find('/') != string::npos ? filename.find('/') : 0);
	string wd = WorkDir::get();
	path = wd;
}

File::File(Filetype type, size_t filesize, string filename, string path)
{
	this->type = type;
	this->filesize = filesize;
	this->filename = filename;
	this->path = path;
}

Filetype File::getType()
{
	return type;
}

size_t File::getSize()
{
	return filesize;
}

string File::getFilename()
{
	return filename;
}

string File::getPath()
{
	return path;
}
