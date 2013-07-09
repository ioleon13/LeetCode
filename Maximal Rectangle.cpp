class Solution {
public:
    int histogram(vector<int>& vec)
    {
        if(vec.empty())
            return 0;
        int n = vec.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = 0;
        right[n-1] = n-1;
        for(int i = 1; i < n; i++)
        {
            int j = i;
            while(j-1 >= 0 && vec[j-1] >= vec[i])
                j = left[j-1];
            left[i] = j;
        }
        for(int i = n-2; i >= 0; i--)
        {
            int j = i;
            while(j+1 < n && vec[j+1] >= vec[i])
                j = right[j+1];
            right[i] = j;    
        }
        int maxVal = 0;
        for(int i = 0; i < n; i++)
        {
            int candi = (right[i] - left[i] + 1) * vec[i];
            maxVal = max(maxVal,candi);
        }
        return maxVal;
    
    }
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int> > vec(m,vector<int>(n));
        for(int i = 0; i < n; i++)
        {
            int total = 0;
            for(int j = 0; j < m; j++)
            {
                total += matrix[j][i] - '0';
                if(matrix[j][i] == '0')
                    total = 0;
                vec[j][i] = total;
            } 
        }    
        int maxVal = 0;
        for(int i = 0; i < m; i++)
            maxVal = max(maxVal,histogram(vec[i]));
        return maxVal;
    }
};