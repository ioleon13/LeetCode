

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
    void buildRec(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, TreeNode*& current, int len, int offset, map<int,int>& hash)
    {
        if(len == 0)
            return;
        int val = preorder[preStart];
        int idx = hash[val] - offset;
        current = new TreeNode(val);
        buildRec(preorder,inorder,preStart+1,inStart,current->left,idx,offset,hash);
        buildRec(preorder,inorder,preStart+idx+1,inStart+idx+1,current->right,len-idx-1,offset+idx+1,hash);
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(preorder.empty() || inorder.empty())
            return NULL;
        int n = preorder.size();
        //assert(n == inorder.size());
        map<int,int> hash;
        for(int i = 0; i < n; i++)
            hash.insert(make_pair(inorder[i],i));
        TreeNode* root = NULL;
        buildRec(preorder,inorder,0,0,root,n,0,hash);
        return root;
        
    }
};
