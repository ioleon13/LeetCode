
class Solution {
public:
    void generate(vector<vector<int> >& ret, vector<int>& vec, map<int,int>& hash, int pos, int n)
    {
        if(pos == n)
        {
            ret.push_back(vec);
            return;
        }
        for(map<int,int>::iterator iter = hash.begin(); iter != hash.end(); iter++)
        {
            if(iter->second > 0)
            {
                iter->second--;
                vec[pos] = iter->first;
                generate(ret,vec,hash,pos+1,n);
                iter->second++;
            }
        }
    }
   
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;        
        if(num.empty())
            return ret;
        int n = num.size();
        map<int,int> hash;
        for(int i = 0; i < n; i++)
            hash[num[i]]++;
        vector<int> vec(n);
        generate(ret,vec,hash,0,n);
        return ret;
        
    }
};