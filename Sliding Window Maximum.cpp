#include <iostream>
#include <vector>
#include <deque>
using namespace std;

typedef pair<int,int> Pair; //first val,second idx
vector<int> maxSlidingWnd(vector<int>& vec, int w)
{
	vector<int> ret;
	if(vec.empty())
		return ret;
	int n = vec.size();
	deque<Pair> deq;
	for(int i = 0; i < w; i++)
	{
		while(!deq.empty() && vec[i] > deq.back().first)
			deq.pop_back();
		deq.push_back(make_pair(vec[i],i));
	}
	for(int i = w; i < n; i++)
	{
		ret.push_back(deq.front().first);
		while(!deq.empty() && vec[i] > deq.back().first)
			deq.pop_back();
		deq.push_back(make_pair(vec[i],i));
		if(deq.front().second <= i-w)
			deq.pop_front();
	}
	ret.push_back(deq.front().first);
	return ret;
}


