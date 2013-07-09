
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if(root == NULL)
            return ret;
        vector<int> vec;
        queue<TreeNode*> que;
        que.push(root);
        int currentLevel = 1;
        int nextLevel = 0;
        while(!que.empty())
        {    
            TreeNode* top = que.front();
            que.pop();
            currentLevel--;
            vec.push_back(top->val);
            if(top->left != NULL)
            {
                que.push(top->left);
                nextLevel++;
            }
            if(top->right != NULL)
            {
                que.push(top->right);
                nextLevel++;
            }
            if(currentLevel == 0)
            {
                ret.push_back(vec);
                vec.clear();
                currentLevel = nextLevel;
                nextLevel = 0;
            }
        }
        return ret;
    }
};

