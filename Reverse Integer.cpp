
class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x == 0)
            return 0;
        bool neg = false;
        long long num = x;
        if(num < 0)
        {
            neg = true;
            num = ~num + 1;
        }    
        long long total = 0;
        while(num)
        {
            int digit = num % 10;
            total = 10*total + digit;
            num /= 10;
        
        }
        if(!neg)
            return total > INT_MAX ? INT_MAX : total;
        else return total > 0x80000000 ? INT_MIN : ~total+1;
    }
};
