#ifndef __UTILS_H_
#define __UTILS_H_

#include "Common.h"


class Utils
{
public:
	static char* GetFormatString(const char* lpFormat, ...)
	{
		static char buff[1024 * 2];

		va_list ap;
		va_start(ap, lpFormat);
		vsprintf(buff, lpFormat, ap);
		va_end(ap);
		return buff;
	}

};

#endif