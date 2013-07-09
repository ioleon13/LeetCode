
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s == NULL)
            return 0;
        int len = strlen(s);
        const char* current = s + len - 1;
        while(current >= s && *current == ' ')
            current--;
        if(current < s)
            return 0;
        int cnt = 0;
        while(current >= s && *current != ' ')
        {
            cnt++;
            current--;
        }
        return cnt;
    }
};