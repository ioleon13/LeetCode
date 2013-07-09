
class Solution {
public:
    bool isValid(vector<int>& vec, int item, int level)
    {
        for(int i = 0; i < level; i++)
        {
            if(vec[i] == item)
                return false;
            if(level - i == abs(item - vec[i]))
                return false;
        }
        return true;
        
    }
    void generate(vector<vector<string> >& ret, vector<int>& vec, int level, int n)
    {
        if(level == n)
        {
            vector<string> tem;
            for(int i = 0; i < n; i++)
            {
                string str(n,'.');
                str[vec[i]] = 'Q';
                tem.push_back(str);
            }
            ret.push_back(tem);
            return;
        }
        for(int i = 0; i < n; i++)
            if(isValid(vec,i,level))
            {
                vec[level] = i;
                generate(ret,vec,level+1,n);
            }
    
    }
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > ret;
        vector<int> vec(n);
        generate(ret,vec,0,n);
        return ret;
        
    }
};