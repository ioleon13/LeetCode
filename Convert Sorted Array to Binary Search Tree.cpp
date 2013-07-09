

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
    void convert(TreeNode*& current, vector<int>& num, int start, int end)
    {
        if(start > end)
        {
            current = NULL;
            return;
        }   
        int mid = start + (end - start)/2;
        current = new TreeNode(num[mid]);
        convert(current->left,num,start,mid-1);
        convert(current->right,num,mid+1,end);
    
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.empty())
            return NULL;
        TreeNode* root;
        convert(root,num,0,num.size()-1);
        return root;
    }
};
