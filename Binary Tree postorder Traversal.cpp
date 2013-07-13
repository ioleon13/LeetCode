
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
    vector<int> postorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        if(root == NULL)
            return ret;
        stack<TreeNode*> sta1;
        stack<TreeNode*> sta2;
        sta1.push(root);
        while(!sta1.empty())    
        {
            TreeNode* top = sta1.top();
            sta1.pop();
            sta2.push(top);
            if(top->left != NULL)
                sta1.push(top->left);
            if(top->right != NULL)
                sta1.push(top->right);
        }
        while(!sta2.empty())
        {
            TreeNode* top = sta2.top();
            sta2.pop();
            ret.push_back(top->val);
            
        }
        return ret;
    }
};


class Solution {
public:
	vector<int> postorderTraversalBetter(TreeNode *root) {
		vector<int> ret;
		if(root == NULL)
			return ret;
		stack<TreeNode*> sta;
		sta.push(root);
		TreeNode* prev = NULL;
		while(!sta.empty())
		{
			TreeNode* current = sta.top();
			if(prev == NULL || current == prev->left || current == prev->right )
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
				ret.push_back(current->val);
			}
			prev = current;

		}
		return ret;
	}
};