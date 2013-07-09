
class Solution {
public:
    bool isMatch(char* haystack, char* needle)
    {
        while(*needle)
            if(*haystack++ != *needle++)
                return false;
        return true;
    
    }    
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(haystack == NULL || needle == NULL)
            return NULL;
        int m = strlen(haystack);
        int n = strlen(needle);
        if(m < n)
            return NULL;
        for(int i = 0; i <= m-n; i++)
            if(isMatch(haystack+i,needle))
                return haystack+i;
        return NULL;
    }
};