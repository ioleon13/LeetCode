
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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        flatten(left);
        flatten(right);
        root->left = NULL;
        root->right = left;
        TreeNode* current = root;
        while(current->right != NULL)
            current = current->right;
        current->right = right;
    
    }
};
