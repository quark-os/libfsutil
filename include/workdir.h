#ifndef _FSUTIL_WORKDIR_H
#define _FSUTIL_WORKDIR_H

#include <string>

using namespace std;

class WorkDir
{
public:

	static string get();
	
	static void set(string path);

};

class WDSetException
{
public:

	WDSetException();
	WDSetException(string triedPath);

	virtual const char* what() const throw();
	
	string& getTriedPath();
	
private:

	string triedPath;
	
};

#endif
