#include <iostream>
using namespace std;

void reverse(char* str, int i, int j)
{
	while(i < j)
	{
		char tem = str[i];
		str[i] = str[j];
		str[j] = tem;
		i++;
		j--;
	}	
}

void rotate(char* str, int k)
{
	if(str == NULL)
		return;
	int n = strlen(str);
	if(k < 0 || k > n)
		return;
	reverse(str,0,n-1-k);
	reverse(str,n-k,n-1);
	reverse(str,0,n-1);
}
