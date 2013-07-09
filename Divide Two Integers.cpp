
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        assert(divisor != 0);
        if(dividend == 0)
            return 0;
        int sig = 1;
        if(dividend < 0)
            sig = ~sig+1;
        if(divisor < 0)
            sig = ~sig+1;
        long long divd = abs((long long)dividend);
        long long divs = abs((long long)divisor);
        long long num = divs;
        long long count = 1;
        int ret = 0;
        while(divd > num)
        {
            num <<= 1;
            count <<= 1;
        }
        while(num >= divs)
        {
            if(divd >= num)
            {
                ret += count;
                divd -= num;
            }
            num >>= 1;
            count >>= 1;
        }
        return sig*ret;
        
    }
};