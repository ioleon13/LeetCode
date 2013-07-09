
class Solution {
public:
    bool isNum(const char* current)
    {
        return *current >= '0' && *current <= '9';
    }
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(str == NULL)
            return 0;
        const char* current = str;
        while(*current != '\0' && *current == ' ')
            current++;
        if(*current == '\0')
            return 0;
        bool neg = false;
        if(*current == '-')
        {
            neg = true;
            current++;
        }
        else if(*current == '+')
            current++;
        if(!isNum(current))
            return 0;
        long long total = 0;
        while(*current != '\0' && isNum(current))
        {
            int digit = *current - '0';
            total = 10*total + digit;
            current++;
        }
        if(!neg)
            return total > INT_MAX ? INT_MAX : (int)total;
        else return total > 0x80000000 ? INT_MIN : ~total+1;
            
    }
};
