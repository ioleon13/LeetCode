
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
    void traverse(vector<vector<int> >& ret, TreeNode* current, int sum, vector<int>& vec)
    {
        if(current == NULL)
            return;
        vec.push_back(current->val);
        int total = sum - current->val;
        if(current->left == NULL && current->right == NULL && total == 0)
            ret.push_back(vec);
        traverse(ret,current->left,total,vec);
        traverse(ret,current->right,total,vec);
        vec.pop_back();
        
    
    
    }
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if(root == NULL)
            return ret;
        vector<int> vec;
        traverse(ret,root,sum,vec);
        return ret;
    }
};

