
class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x < 0)
            return false;
        if(x == 0)
            return true;
        int factor = 1;
        int num = x;
        while(num/10)
        {
            factor *= 10;
            num /= 10;
        }
        while(x)
        {
            int left = x / factor;
            int right = x % 10;
            if(left != right)
                return false;
            x %= factor;
            x /= 10;
            factor /= 100;
        }
        return true;
    }
};
