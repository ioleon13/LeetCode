
class Solution {
public:
    typedef pair<int,int> Pair;
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.empty())
            return 0;
        int n = num.size();
        map<int,Pair> hash;
        int maxVal = 0;
        for(int i = 0; i < n; i++)
        {
            if(!hash.count(num[i]))
            {
                hash.insert(make_pair(num[i],Pair(num[i],num[i])));
                if(hash.count(num[i]+1))
                    hash[num[i]].second = hash[num[i]+1].second;
                if(hash.count(num[i]-1))
                    hash[num[i]].first = hash[num[i]-1].first;
                
                hash[hash[num[i]].first].second = hash[num[i]].second;
                hash[hash[num[i]].second].first = hash[num[i]].first;
            }
            maxVal = max(maxVal,hash[num[i]].second - hash[num[i]].first + 1);
        }
        return maxVal;
    }
};