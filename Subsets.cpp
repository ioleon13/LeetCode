

class Solution {
public:
    vector<int> generate(vector<int>& S, int mask, int n)
    {
        vector<int> vec;
        for(int i = 0; i < n; i++)
            if(mask & (1 << i) )
                vec.push_back(S[i]);
        return vec;
    }
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if(S.empty())
            return ret;
        int n = S.size();
        int upper = 1 << n;
        sort(S.begin(),S.end());
        for(int i = 0; i < upper; i++)
        {
            vector<int> vec = generate(S,i,n);
            ret.push_back(vec);
        }
        return ret;
    }
};


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
        }
    
    }
    vector<vector<int> > subsets(vector<int> &S) {
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