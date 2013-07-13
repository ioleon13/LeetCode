
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
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left,right) + 1;
    }
};


class Solution {
public:
	int maxDepth(TreeNode *root){
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(root == NULL)
			return 0;
		stack<TreeNode*> sta;
		TreeNode* prev = NULL;
		sta.push(root);
		int maxHeight = 0;
		while(!sta.empty())
		{
			TreeNode* current = sta.top();
			if(prev == NULL || prev->left == current || prev->right == current)
			{
				if(current->left != NULL)
					sta.push(current->left);
				else if(current->right != NULL)
					sta.push(current->right);
			}
			else if(current->left == prev)
			{
				if(current->right != NULL)
					sta.push(current->right);
			}
			else
			{
				sta.pop();
			}
			prev = current;
			if(sta.size() > maxHeight)
				maxHeight = sta.size();
		}
		return maxHeight;
	}
};