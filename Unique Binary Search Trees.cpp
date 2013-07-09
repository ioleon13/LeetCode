
class Solution {
public:
    int countRec(int n)
    {
        if(n == 0)
            return 1;
        if(n == 1)
            return 1;
        int ret = 0;
        for(int i = 0; i <= n-1; i++)
            ret += countRec(i)*countRec(n-1-i);
        return ret;
    }
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n < 0)
            return 0;
        return countRec(n);
                
    }
};




class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n < 0)
            return 0;
        vector<int> vec(n+1);
        vec[0] = 1;
        vec[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            int ret = 0;
            for(int j = 0; j <= i-1; j++)
                ret += vec[j]*vec[i-1-j];
            vec[i] = ret;
        }
        return vec[n];
    }
};
