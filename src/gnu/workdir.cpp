#include "workdir.h"

#include <unistd.h>

string WorkDir::get()
{
	return string(getcwd(0, 0));
}

void WorkDir::set(string path)
{
	if(chdir(path.c_str()) != 0)
	{
		throw WDSetException(path);
	}
}

WDSetException::WDSetException()
{
	this->triedPath = "<unspecified>";
}

WDSetException::WDSetException(string triedPath)
{
	this->triedPath = triedPath;
}

const char* WDSetException::what() const throw()
{
	return "Failed to change working directory";
}
