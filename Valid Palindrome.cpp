

class Solution {
public:
    bool isUpperAlpha(char c)
    {
        return c >= 'A' && c <= 'Z';
    }
    bool isAlphaNum(char c)
    {
        return c >= '0' && c <= '9' ||  c >= 'a' && c <= 'z' || isUpperAlpha(c);
    }
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.empty())
            return true;
        int n = s.size();
        int i = 0;
        int j = n-1;
        while(i < j)
        {
            char left = s[i];
            char right = s[j];
            if(!isAlphaNum(left))
            {
                i++;
                continue;
            }
            if(!isAlphaNum(right))
            {
                j--;
                continue;
            }
            if(isUpperAlpha(left))
                left = left + ('a' - 'A');
            if(isUpperAlpha(right))
                right = right + ('a' - 'A');
            if(left != right)
                return false;   
            i++;
            j--;
        }
        return true;
    }
};

