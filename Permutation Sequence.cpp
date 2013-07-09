
class Solution {
public:
    void swap(vector<int>& vec, int i, int j)
    {
        int tem = vec[i];
        vec[i] = vec[j];
        vec[j] = tem;
    }
    void nextPermutation(vector<int>& vec, int n)
    {
        int i = n-1;
        while(i-1 >= 0 && vec[i-1] >= vec[i])
            i--;
        if(i < 1)
        {
            reverse(vec.begin(),vec.end());
            return;
        }
        int j = n-1;
        while(j >= i && vec[j] <= vec[i-1])
            j--;
        swap(vec,i-1,j);
        reverse(vec.begin()+i,vec.end());
    }
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        assert(n >= 1 && n <= 9);
        
        if(k <= 0)
            return string("");
        vector<int> vec(n);
        for(int i = 1; i <= n; i++)
            vec[i-1] = i;
        for(int i = 1; i < k; i++)
            nextPermutation(vec,n);
        string ret(n,' ');
        for(int i = 0; i < n; i++)
            ret[i] = vec[i] + '0';
        return ret;
            
    }
};