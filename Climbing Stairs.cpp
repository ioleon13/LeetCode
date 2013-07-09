
class Solution {
public:
    int climbStairsRec(int n)
    {
        if(n == 0 || n == 1)
            return 1;
        return climbStairsRec(n-1) + climbStairsRec(n-2);
    
    }
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n < 0)
            return 0;
        return climbStairsRec(n);
    }
};

class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n < 0)
            return 0;
        vector<int> vec(n+1);
        vec[0] = 1;
        vec[1] = 1;
        for(int i = 2; i <= n; i++)
            vec[i] = vec[i-1] + vec[i-2];
        return vec[n];
    }
};