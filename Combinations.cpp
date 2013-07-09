
class Solution {
public:
    void generate(vector<vector<int> > & ret, vector<int>& vec, int n, int k, int pos, int prev)
    {
        if(pos == k)
        {
            ret.push_back(vec);
            return;
        }
        for(int i = prev; i <= n-k+pos+1; i++)
        {
            vec[pos] = i;
            generate(ret,vec,n,k,pos+1,i+1);
        }
    }
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        vector<int> vec(k);
        generate(ret,vec,n,k,0,1);
        return ret;
    }
};
