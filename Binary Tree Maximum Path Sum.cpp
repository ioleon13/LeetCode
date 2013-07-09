
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findMaxRec(TreeNode* current, int& maxval)
    {
        if(current == NULL)
            return 0;
        int left = findMaxRec(current->left,maxval);
        int right = findMaxRec(current->right,maxval);
        int candi = max(0,left) + max(0,right) + current->val;
        if(candi > maxval)
            maxval = candi;
        if(left < 0 && right < 0)
            return current->val;
        return max(left, right) + current->val;
            
    }
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return 0;
        int maxval = INT_MIN;
        findMaxRec(root,maxval);
        return maxval;
    }
};