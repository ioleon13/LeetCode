#include <iostream>
#include <stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

int getHeightRec(TreeNode* current)
{
	if(current == NULL)
		return 0;
	return max(getHeightRec(current->left),getHeightRec(current->right)) + 1;
}

int getHeight(TreeNode* root)
{
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

