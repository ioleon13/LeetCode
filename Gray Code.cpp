
class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        if(n < 0)
            return ret;
        if(n == 0)
        {
            ret.push_back(0);
            return ret;
        }    
            
        int upper = 1 << n;
        for(int i = 0; i < upper; i++)
            ret.push_back(i ^ (i >> 1));
        return ret;
            
    }
};


class Solution {
public:
    void generate(vector<int>& vec, int offset)
    {
        vector<int> newVec = vec;
        reverse(newVec.begin(),newVec.end());
        for(int i = 0; i < newVec.size(); i++)
        {
            newVec[i] |= (1 << offset);
            vec.push_back(newVec[i]);
        }
    }
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        if(n < 0)
            return ret;
        if(n == 0)
        {
            ret.push_back(0);
            return ret;
        }
        ret.push_back(0);
        ret.push_back(1);
        for(int i = 1; i < n; i++)
            generate(ret,i);
        return ret;
    }
};
