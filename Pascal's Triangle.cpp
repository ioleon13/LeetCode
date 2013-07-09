
class Solution {
public:
    vector<int> generateNext(vector<int>& vec, int n)
    {
        vector<int> ret(n);
        ret[0] = 1;
        ret[n-1] = 1;
        for(int i = 1; i < n-1; i++)
            ret[i] = vec[i] + vec[i-1];
        return ret;
    }
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> > ret;
        if(numRows <= 0)
            return ret;
        vector<int> vec(1,1);
        ret.push_back(vec);
        for(int i = 1; i < numRows; i++)
        {
            vec = generateNext(vec,i+1);
            ret.push_back(vec);
        }
        return ret;
    }
};
