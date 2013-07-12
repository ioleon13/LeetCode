#include <iostream>
using namespace std;

int countWord(const string& str)
{
	if(str.empty())
		return 0;
	int n = str.size();
	bool inword = false;
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		if(str[i] == ' ' && inword)
			inword = false;
		if(str[i] != ' ' && !inword)
		{
			inword = true;
			cnt++;
		}
	}
	return cnt;
}

