
class Solution {
public:
    int getVal(char ch)
    {
        switch(ch){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: break;
        };
    }
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.empty())
            return 0;
        int n = s.size();
        int total = getVal(s[0]);
        int prev = getVal(s[0]);
        for(int i = 1; i < n; i++)
        {
            int current = getVal(s[i]);
            total += current;
            if(current > prev)
                total -= 2*prev;
            prev = current;
        
        }
        return total;
    }
};
