
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
    vector<int> preorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        if(root == NULL)
            return ret;
        stack<TreeNode*> sta;
        sta.push(root);
        while(!sta.empty())
        {
            TreeNode* top = sta.top();
            sta.pop();
            ret.push_back(top->val);
            if(top->right != NULL)
                sta.push(top->right);
            if(top->left != NULL)
                sta.push(top->left);
  
        }
        return ret;
    }
};