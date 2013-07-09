
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.empty())
            return 0;
        int n = s.size();
        map<char,int> hash;
        int maxLen = 0;
        int start = 0;
        for(int i = 0; i < n; i++)
        {
            if(!hash.count(s[i]))
                hash.insert(make_pair(s[i],i));
            else
            {
                int idx = hash[s[i]];
                int len = i-start;
                if(len > maxLen)
                    maxLen = len;
                start = idx+1;
                hash.clear();
                i = start-1;
            }
        
        }
        return max(maxLen,n-start);
    }
};