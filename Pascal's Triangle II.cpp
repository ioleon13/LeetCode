
class Solution {
public:
    void generate(vector<int>& vec, int upper)
    {
        for(int i = upper-1; i >= 1; i--)
            vec[i] = vec[i] + vec[i-1];
    }
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(rowIndex < 0)
            return vector<int>();
        vector<int> vec(rowIndex+1,1);
        for(int i = 2; i <= rowIndex; i++)
            generate(vec,i);
        return vec;
        
    }
};
