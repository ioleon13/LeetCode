
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if(root == NULL)
            return ret;
        vector<int> vec;
        stack<TreeNode*> sta1;
        stack<TreeNode*> sta2;
        bool iseven = true;
        sta1.push(root);
        while(!sta1.empty())
        {
            TreeNode* top = sta1.top();
            sta1.pop();
            vec.push_back(top->val);
            if(iseven)
            {
                if(top->left != NULL)
                    sta2.push(top->left);
                if(top->right != NULL)
                    sta2.push(top->right); 
            }
            else 
            {
                if(top->right != NULL)
                    sta2.push(top->right);
                if(top->left != NULL)
                    sta2.push(top->left);
            }
            if(sta1.empty())
            {
                ret.push_back(vec);
                vec.clear();
                iseven = !iseven;
                swap(sta1,sta2);
            }
        
        }
        return ret;
    }
};