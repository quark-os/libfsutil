#ifndef _FSUTIL_SCAN_H 
#define _FSUTIL_SCAN_H

#include "file.h"

using namespace std;

class DirectoryScanner
{
public:

	void scan(string dir);
	
	virtual void scanCallback(File& file) = 0;
	
};

#endif
