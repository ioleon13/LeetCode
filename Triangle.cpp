

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(triangle.empty())
            return 0;
        int n = triangle.size();
        vector<int> vec(triangle[n-1]);
        for(int i = n-2; i >= 0; i--)
            for(int j = 0; j <= i; j++)
                vec[j] = min(vec[j],vec[j+1]) + triangle[i][j];
        return vec[0];
    }
};
