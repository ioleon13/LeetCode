
class Solution {
public:
    void swap(vector<int>& vec, int i, int j)
    {
        int tem = vec[i];
        vec[i] = vec[j];
        vec[j] = tem;
    }
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.empty())
            return;
        int n = num.size();
        int i = n-1;
        while(i-1 >= 0 && num[i-1] >= num[i])
            i--;
        if(i < 1)
        {
            reverse(num.begin(),num.end());
            return;
        }
        int j = n-1;
        while(j >= i && num[j] <= num[i-1])
            j--;
        swap(num,i-1,j);
        reverse(num.begin()+i,num.end());

    }
    
};

