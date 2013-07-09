
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
    bool isSymmetricRec(TreeNode* currentLeft, TreeNode* currentRight)
    {
        if(currentLeft == NULL && currentRight == NULL)
            return true;
        if(currentLeft == NULL || currentRight == NULL)
            return false;
        if(currentLeft->val != currentRight->val)
            return false;
        return isSymmetricRec(currentLeft->left,currentRight->right) && isSymmetricRec(currentLeft->right,currentRight->left);
    
    }
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return true;
        return isSymmetricRec(root->left,root->right);
    }
};
