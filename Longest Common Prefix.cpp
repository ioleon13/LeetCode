
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ret = "";
        if(strs.empty())
            return ret;
        int n = strs.size();
        int maxLen = 0;
        for(int i = 0; i < n; i++)
        {
            int len = strs[i].size();
            if(len > maxLen)
                maxLen = len;
        }
        for(int i = 0; i < maxLen; i++)
        {
            char tem = strs[0][i];
            for(int j = 1; j < n; j++)
                if(strs[j][i] != tem)
                    return ret;
            ret += tem;
        }
        return ret;
    }
};