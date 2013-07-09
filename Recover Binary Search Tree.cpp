
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
    void swap(TreeNode* first, TreeNode* second)
    {
        int tem = first->val;
        first->val = second->val;
        second->val = tem;
    }
    void traverse(TreeNode* current, TreeNode*& prev, TreeNode*& first, TreeNode*& second)
    {
        if(current == NULL)
            return;
        traverse(current->left,prev,first,second);
        if(prev != NULL && prev->val > current->val)
        {
            if(first == NULL)
            {
                first = prev;
                second = current;
            }
            else second = current;
        
        }
        prev = current;
        traverse(current->right,prev,first,second);
    }
    
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return;
        TreeNode* prev = NULL;
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        traverse(root,prev,first,second);
        swap(first,second);
    }
};
