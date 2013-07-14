class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ret = "";
        int minLen = INT_MAX;
        if(S.empty() || T.empty())
            return ret;
        int m = S.size();
        int n = T.size();
        map<char,int> hasFound;
        map<char,int> needFind;
        for(int i = 0; i < n; i++)
            needFind[T[i]]++;
        int cnt = 0;
        int start = 0;
        int end = 0;
        for(int i = end; i < m; i++)
        {
            if(!needFind.count(S[i]))
                continue;
            hasFound[S[i]]++;
            if(hasFound[S[i]] <= needFind[S[i]])
                cnt++;
            
            if(cnt == n)
            {
                end = i;
                while(!needFind.count(S[start]) || hasFound[S[start]] > needFind[S[start]])
                {
                    if(needFind.count(S[start]) )
                        hasFound[S[start]]--;
                    start++;
                }
                string tem = S.substr(start,end-start+1);
                
                if(tem.size() < minLen)
                {
                    ret = tem;
                    minLen = tem.size();
                }
            }
        }
        return ret;
    }
};