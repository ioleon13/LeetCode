class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(*s == '\0')
        {
            if(*p == '\0')
                return true;
            else if(*p == '*')
            {
                while(*p == '*')
                    p++;
                return *p == '\0';
            }
            else return false;
        }
        if(*p == '\0')
            return false;
        else if(*p == *s || *p == '?')
            return isMatch(s+1,p+1);
        else if(*p == '*')
            return isMatch(s,p+1) || isMatch(s+1,p);
        else return false;
    }
};