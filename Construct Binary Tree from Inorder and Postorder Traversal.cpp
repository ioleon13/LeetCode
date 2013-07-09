

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
    void buildRec(vector<int>& inorder, vector<int>& postorder, TreeNode*& current, int inStart, int postStart, int len, int offset, map<int,int>& hash)
    {
        if(len == 0)
            return;
        int val = postorder[len-1];
        int idx = hash[val] - offset;
        current = new TreeNode(val);
        buildRec(inorder,postorder,current->left,inStart,postStart,idx,offset,hash);
        buildRec(inorder,postorder,current->right,inStart+idx+1,postStart+idx,len-idx-1,offset+idx+1,hash);
    
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(inorder.empty() || postorder.empty())
            return NULL;
        int n = inorder.size();
        assert(n == postorder.size());
        map<int,int> hash;
        for(int i = 0; i < n; i++)
            hash.insert(make_pair(inorder[i],i));
        TreeNode* root = NULL;
        buildRec(inorder,postorder,root,0,0,n,0,hash);
        return root;
    }
};
