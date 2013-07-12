
#include <iostream>
using namespace std;

void removeSpace(char* str)
{
	if(str == NULL)
		return;
	int len = strlen(str);
	int pivpos = -1;
	for(int i = 0; i < len; i++)
	{
		if(str[i] != ' ')
			str[++pivpos] = str[i];
	}
	str[pivpos+1] = '\0';

}

