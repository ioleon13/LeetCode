
class Solution {
public:
    string find(const string& str, int i, int j, int n)
    {
        while(i >= 0 && j < n)
        {
            if(str[i] == str[j])
            {
                i--;
                j++;
            }
            else break;
        }
        i++;
        j--;
        return str.substr(i,j-i+1);
    
    }
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ret = "";
        if(s.empty())
            return ret;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            string str1 = find(s,i,i,n);
            string str2 = find(s,i-1,i,n);
            if(str1.size() > ret.size())
                ret = str1;
            if(str2.size() > ret.size())
                ret = str2;
        }
        return ret;

    }
};
