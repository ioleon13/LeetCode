
class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> vec(m,0);
        vec[m-1] = 1;
        for(int j = n-1; j >= 0; j--)
            for(int i = m-1; i >= 0; i--)
            {
                int downVal = i+1 < m ? vec[i+1] : 0;
                vec[i] = vec[i] + downVal;
            }
        return vec[0];
    }
};