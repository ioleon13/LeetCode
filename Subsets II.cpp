
class Solution {
public:
    void subsetsRec(vector<vector<int> >& ret, vector<int>& vec, vector<int>& S, int prev, int level, int n)
    {
        vector<int> tem;
        for(int i = 0; i < level; i++)
            tem.push_back(vec[i]);
        ret.push_back(tem);
        
        for(int i = prev; i < n; i++)
        {
            vec[level] = S[i];
            subsetsRec(ret,vec,S,i+1,level+1,n);
            while(i+1 < n && S[i] == S[i+1])
                i++;
        }
    
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if(S.empty())
            return ret;
        int n = S.size();
        sort(S.begin(),S.end());
        vector<int> vec(n);
        subsetsRec(ret,vec,S,0,0,n);
        return ret;
    }
    
};