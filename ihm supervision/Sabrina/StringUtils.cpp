//---------------------------------------------------------------------------

#pragma hdrstop

#include "StringUtils.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

char * StringUtils::magicConvert(UnicodeString src)
{
	// Petit code de derrière les fagots :
	wchar_t * tmp;
	tmp = src.w_str();
	int len = wcslen(tmp);
	char * ret = new char[len+1];
	wcstombs(ret, tmp, len);
	return ret;
}
