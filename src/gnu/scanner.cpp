#include "scanner.h"
#include "workdir.h"

#include <sys/stat.h>
#include <dirent.h>

#include <iostream>

void DirectoryScanner::scan(string dir)
{
	string oldWD = WorkDir::get();
	try
	{
		WorkDir::set(dir);
		DIR* dir = opendir(".");
		if(dir != NULL)
		{
			
			struct dirent* nativeEntry;
			while(nativeEntry = readdir(dir))
			{
				string filename(nativeEntry->d_name);
				File file(filename);
				this->scanCallback(file);
			}
		}
		else
		{
			// TODO: Throw exception
		}
		WorkDir::set(oldWD);
	}
	catch(exception& e)
	{
		WorkDir::set(oldWD);
		cout << "Error scanning directory: " << e.what() << endl;
	}
}
