
class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0)
            return 1;
        bool neg = false;
        if(n < 0)
        {
            neg = true;
            n = ~n;
        }
        double val = 1;
        double factor = x;
        while(n)
        {
            if(1 & n)
                val *= factor;
            factor *= factor;
            n >>= 1;
        }
        if(!neg)
            return val;
        return 1/val/x;
    }
};

