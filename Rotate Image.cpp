
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.empty())
            return;
        int n = matrix.size();
        for(int layer = 0; layer < n/2; layer++)
        {
            int first = layer;
            int last = n - 1 - first;
            for(int i = first; i < last; i++)
            {
                int offset = i - first;
                int tem = matrix[layer][i];
                matrix[layer][i] = matrix[last-offset][layer];
                matrix[last-offset][layer] = matrix[last][last-offset];
                matrix[last][last-offset] = matrix[i][last];
                matrix[i][last] = tem;
            }
        }
    }
};
