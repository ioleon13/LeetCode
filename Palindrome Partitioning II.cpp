class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.empty())
            return 0;
        int n = s.size();
        vector<vector<int> > check(n+1,vector<int>(n+1));
        vector<int> vec(n+1);
        for(int i = 0; i <= n; i++)
            vec[i] = n-i-1;
        for(int i = n-1; i >= 0; i--)
            for(int j = i; j < n; j++)
                if(s[i] == s[j] && (j-i <= 2 || check[i+1][j-1]))
                {
                    check[i][j] = 1;
                    vec[i] = min(vec[i],vec[j+1] + 1);
                }
        return vec[0];
    }
};