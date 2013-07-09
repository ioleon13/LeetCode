
class Solution {
public:
    string convert(int num, char one, char five, char ten)
    {
        string ret = "";
     
        if(num == 9)
        {
            ret += one;
            ret += ten;
            return ret;
        }
        if(num >= 5)
        {
            ret += five;
            while(num-- > 5)
                ret += one;
            return ret;
        }
        if(num == 4)
        {
            ret += one;
            ret += five;
            return ret;
        }
        if(num >= 1)
        {
            while(num-- > 0)
                ret += one;
            return ret;
        }
        return ret;
    }
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        string ret = "";
        assert(num >= 1 && num <= 3999);
        ret += convert(num/1000,'M',' ',' ');
        ret += convert(num/100%10,'C','D','M');
        ret += convert(num/10%10,'X','L','C');
        ret += convert(num%10,'I','V','X');
        return ret;
    }
};