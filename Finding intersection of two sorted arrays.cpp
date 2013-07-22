#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findIntersection(vector<int>& A, vector<int>& B)
{
	vector<int> ret;
	if(A.empty() || B.empty())
		return ret;
	int m = A.size();
	int n = B.size();
	int i = 0;
	int j = 0;
	while(i < m && j < n)
	{
		if(A[i] < B[j])
			i++;
		else if(A[i] > B[j])
			j++;
		else
		{
			ret.push_back(A[i]);
			i++;
			j++;
		}
	}
	return ret;
}

vector<int> findIntersection(vector<int>& A, vector<int>& B)
{
	vector<int> ret;
	if(A.empty() || B.empty())
		return ret;
	int m = A.size();
	int n = B.size();
	for(int i = 0; i < m; i++)
		if(binary_search(B.begin(),B.end(),A[i]))
			ret.push_back(A[i]);
	return ret;
}

