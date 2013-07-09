
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
    int getHeight(TreeNode* current)
    {
        if(current == NULL)
            return 0;
        return max(getHeight(current->left),getHeight(current->right)) + 1;
    }
    void traverse(TreeNode* current, int& total, int level, vector<int>& vec)
    {
        if(current == NULL)
            return;
        vec[level] = current->val;
        if(current->left == NULL && current->right == NULL)
        {
            int sum = 0;
            for(int i = 0; i <= level; i++)
                sum = sum * 10 + vec[i];
            total += sum;
        }
        traverse(current->left,total,level+1,vec);
        traverse(current->right,total,level+1,vec);
         
    
    }
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return 0;
        int n = getHeight(root);
        vector<int> vec(n);
        int total = 0;
        traverse(root,total,0,vec);
        return total;
        
    }
};