
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
    int isBalancedRec(TreeNode* current)
    {
        if(current == NULL)
            return 0;
        int left = isBalancedRec(current->left);
        int right = isBalancedRec(current->right);
        if(left == -1 || right == -1)
            return -1;
        if(abs(left - right) > 1)
            return -1;
        return max(left,right) + 1;
    
    }
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return isBalancedRec(root) != -1;
    }
};


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
    bool isBalancedRec(TreeNode* current, int& height)
    {
        if(current == NULL)
        {
            height = 0;
            return true;
        }
        int heightLeft = 0;
        int heightRight = 0;
        bool left = isBalancedRec(current->left, heightLeft);
        bool right = isBalancedRec(current->right, heightRight);
        if(!left || !right)
            return false;
        if(abs(heightLeft - heightRight) > 1)
            return false;
        height = max(heightLeft,heightRight) + 1;
        return true;
    }
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int height;
        return isBalancedRec(root,height);
    }
};
