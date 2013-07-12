
#include <iostream>
#include <vector>
using namespace std;

vector<int> multiplication(vector<int>& num)
{
	if(num.empty())
		return vector<int>();
	int n = num.size();
	vector<int> vec(n,1);
	int left = num[0];
	int right = num[n-1];
	for(int i = 1; i < n; i++)
	{
		vec[i] *= left;
		left *= num[i];
		vec[n-1-i] *= right;
		right *= num[n-1-i];
	}
	return vec;
}
