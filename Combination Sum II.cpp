class Solution {
public:
   void combination(vector<vector<int> >& ret, vector<int>& num, int prev, int n, int target, vector<int>& vec, int sum, int level)
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
        for(int i = prev+1; i < n; i++)
        {
            vec[level] = num[i];
            combination(ret,num,i,n,target,vec,num[i]+sum,level+1);
            while(i+1 < n && num[i] == num[i+1])
                i++;
        }
    
    
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if(num.empty())
            return ret;
        int n = num.size();
        sort(num.begin(),num.end());
        vector<int> vec(100);
        combination(ret,num,-1,n,target,vec,0,0);
        return ret;
    }
};
