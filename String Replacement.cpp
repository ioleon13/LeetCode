
#include <iostream>
using namespace std;


bool isMatch(char* str, const char* pattern)
{
	while(*pattern)
		if(*str++ != *pattern++)
			return false;
	return true;

}

void stringReplace(char* str, const char* pattern)
{
	if(str == NULL || pattern == NULL)
		return;
	char* slow = str;
	char* fast = str;
	int slen = strlen(str);
	int plen = strlen(pattern);
	if(slen < plen)
		return;
	while(*fast != '\0')
	{
		bool replace = false;
		while(isMatch(fast,pattern))
		{
			fast += plen;
			replace = true;
		}
		if(replace)
			*slow++ = 'X';
		if(*fast != '\0')
			*slow++ = *fast++;
	}
	*slow = '\0';

}
