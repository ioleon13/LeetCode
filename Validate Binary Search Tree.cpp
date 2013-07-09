
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
    bool isValidRec(TreeNode* current, int minval, int maxval)
    {
        if(current == NULL)
            return true;
        if(current->val >= maxval || current->val <= minval)
            return false;
        return isValidRec(current->left, minval, current->val) && isValidRec(current->right,current->val,maxval);
    
    }
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return true;
        int minval = INT_MIN;
        int maxval = INT_MAX;
        return isValidRec(root,minval,maxval);
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
    bool isValidRec(TreeNode* current, TreeNode*& prev)
    {
        if(current == NULL)
            return true;
        if(!isValidRec(current->left,prev))
            return false;
        if(prev != NULL && prev->val >= current->val)
            return false;
        prev = current;
        return isValidRec(current->right,prev);
        
    
    }
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return true;
        TreeNode* prev = NULL;
        return isValidRec(root,prev);
    }
};
