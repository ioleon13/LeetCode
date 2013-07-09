
class Solution {
public:
    void generateRec(vector<string>& ret, string& str, int left, int right, int pos, int n)
    {
        if(pos == n)
        {
            ret.push_back(str);
            return;
        }
        if(left > 0)
        {
            str[pos] = '(';
            generateRec(ret,str,left-1,right,pos+1,n);
        }
        if(right > left)
        {
            str[pos] = ')';
            generateRec(ret,str,left,right-1,pos+1,n);
        }
    
    }
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        if(n <= 0)
            return ret;
        string str(2*n,' ');
        generateRec(ret,str,n,n,0,2*n);
        return ret;
    }
};