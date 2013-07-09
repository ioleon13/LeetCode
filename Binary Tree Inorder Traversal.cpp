
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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        if(root == NULL)
            return ret;
        stack<TreeNode*> sta;
        TreeNode* current = root;
        while(!sta.empty() || current)
        {
            while(current != NULL)
            {
                sta.push(current);
                current = current->left;
            }
            TreeNode* top = sta.top();
            sta.pop();
            ret.push_back(top->val);
            current = top->right;
        }
        return ret;
    }
};