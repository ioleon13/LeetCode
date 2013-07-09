
class Solution {
public:
    void combination(vector<vector<int> >& ret, vector<int>& candidates, int prev, int n, int target, vector<int>& vec, int sum, int level)
    {
        if(sum > target)
            return;
        if(sum == target)
        {
            vector<int> tem;
            for(int i = 0; i < level; i++)
                tem.push_back(vec[i]);
            ret.push_back(tem);
            return;
        }
        for(int i = prev; i < n; i++)
        {
            vec[level] = candidates[i];
            combination(ret,candidates,i,n,target,vec,candidates[i]+sum,level+1);
        }
    
    
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if(candidates.empty())
            return ret;
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int> vec(100);
        combination(ret,candidates,0,n,target,vec,0,0);
        return ret;
    }
};