
class Solution {
public:
    bool isSingle(char c)
    {
        return c >= '1' && c <= '9';
    }
    bool isDouble(char c1, char c2)
    {
        int digit1 = c1 - '0';
        int digit2 = c2 - '0';
        int total = 10*digit1 + digit2;
        return total >= 10 && total <= 26;
    }
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.empty())
            return 0;
        int n = s.size();
        vector<int> vec(n+1);
        vec[0] = 1;
        vec[1] = isSingle(s[0]);
        for(int i = 2; i <= n; i++)
            vec[i] = isSingle(s[i-1])*vec[i-1] + isDouble(s[i-2],s[i-1])*vec[i-2];
        return vec[n];
    }
};