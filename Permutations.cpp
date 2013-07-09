
class Solution {
public:
    void swap(vector<int>& num, int i, int j)
    {
        int tem = num[i];
        num[i] = num[j];
        num[j] = tem;
    }
    void generate(vector<vector<int> >& ret, vector<int>& num, int start, int end)
    {
        if(start > end)
        {
            ret.push_back(num);
            return;
        }
        generate(ret,num,start+1,end);
        for(int i = start+1; i <= end; i++)
        {
            swap(num,start,i);
            generate(ret,num,start+1,end);
            swap(num,i,start);
        }
    
    }
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if(num.empty())
            return ret;
        int n = num.size();
        generate(ret,num,0,n-1);
        return ret;
    }
};
