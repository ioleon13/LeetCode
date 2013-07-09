
class Solution {
public:
    bool isValid(vector<int>& vec, int item, int level)
    {
        for(int i = 0; i < level; i++)
        {
            if(vec[i] == item)
                return false;
            if(level - i == abs(item - vec[i]))
                return false;
        }
        return true;
        
    }
    void generate(int& total, vector<int>& vec, int level, int n)
    {
        if(level == n)
        {
            total++;
            return;
        }
        for(int i = 0; i < n; i++)
            if(isValid(vec,i,level))
            {
                vec[level] = i;
                generate(total,vec,level+1,n);
            }
    
    }
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> vec(n);
        int total = 0;
        generate(total,vec,0,n);
        return total;
    }
};
