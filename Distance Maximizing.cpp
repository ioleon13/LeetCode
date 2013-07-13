#include <iostream>
#include <vector>
#include <algorithm>   
#include <set>
using namespace std;



int findMaxDist(vector<int>& height)
{
	if(height.empty())
		return 0;
	int n = height.size();
	vector<int> start;
	set<int> hash;
	int minVal = INT_MAX;
	for(int i = 0; i < n; i++)
		if(height[i] < minVal)
		{
			start.push_back(i);
			minVal = min(minVal,height[i]);
		}
	int m = start.size();
	int maxDist = 0;
	int j = n-1;
	int i = 0;
	while(!start.empty())
	{
		i = start.back();
		while(j >= 0)
		{
			if(!hash.count(j) && height[j] > height[i])
				break;
			j--;	
		}
		if(j < 0)
			return maxDist;
		maxDist = max(maxDist,j-i);
		start.pop_back();
	}
	return maxDist;
}
int main()
{
	int a[] = {4,3,5,2,1,3,2,3};
	vector<int> vec(&a[0],&a[0]+sizeof(a)/sizeof(*a));
	cout<<findMaxDist(vec);

	return 0;
}