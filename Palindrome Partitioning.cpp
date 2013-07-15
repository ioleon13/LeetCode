class Solution {
public:
    bool isPalindrome(const string& str)
    {
        if(str.empty())
            return false;
        int n = str.size();
        int i = 0;
        int j = n-1;
        while(i < j)
        {
            if(str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    
    }
    void generate(vector<vector<string> >& ret, vector<string>& vec, string s, int start, int end)
    {
        if(start > end)
        {
            ret.push_back(vec);
            return;
        }
        for(int i = start; i <= end; i++)
        {
            string tem = s.substr(start,i-start+1);
            if(isPalindrome(tem))
            {
                vec.push_back(tem);
                generate(ret,vec,s,i+1,end);
                vec.pop_back();
            }
        
        }
    
    }
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > ret;
        if(s.empty())
            return ret;
        int n = s.size();
        vector<string> vec;
        generate(ret,vec,s,0,n-1);
        return ret;
    }
};