
class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = S.size();
        int n = T.size();
        vector<vector<int> > vec(m+1,vector<int>(n+1));
        for(int i = 0; i <= m; i++)
            vec[i][0] = 1;
        for(int i = 1; i <= n; i++)
            vec[0][i] = 0;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
            {
                if(S[i-1] != T[j-1])
                    vec[i][j] = vec[i-1][j];
                else vec[i][j] = vec[i-1][j] + vec[i-1][j-1];
            
            }
        return vec[m][n];
    }
};

class Solution {
public:
    int countRec(string S, string T, int sstart, int tstart, int m, int n)
    {
        if(tstart == n)
            return 1;
        if(sstart == m)
            return 0;
        int ret = 0;
        for(int i = sstart; i < m; i++)
        {
            if(T[tstart] == S[i])
                ret += countRec(S,T,i+1,tstart+1,m,n);
        }
        return ret;
    }
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return countRec(S,T,0,0,S.size(),T.size());
    }
};

