
class Solution {
public:
    string count(string str)
    {
        if(str.empty())
            return string("");
        int n = str.size();
        char tem = str[0];
        int cnt = 1;
        string ret = "";
        for(int i = 1; i < n; i++)
        {
            if(str[i] == tem)
                cnt++;
            else
            {
                ret += cnt + '0';
                ret += tem;
                tem = str[i];
                cnt = 1;
            }
        }
        ret += cnt + '0';
        ret += tem;
        return ret;
    }
    
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 0)
            return string("");
        string str(1,'1');
        for(int i = 1; i < n; i++)
            str = count(str);
        return str;
        
    }
};