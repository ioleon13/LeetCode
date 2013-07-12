
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traverse(vector<int>& vec, TreeNode* current, int level)
{
	if(level < 0)
		return;
	if(level == 0)
	{
		vec.push_back(current->val);
		return;
	}
	traverse(vec,current->left,level-1);
	traverse(vec,current->right,level-1);
}

int getHeight(TreeNode* current)
{
	if(current == NULL)
		return 0;
	return max(getHeight(current->left),getHeight(current->right) ) + 1;
}

vector<vector<int> > levelTraverse(TreeNode* root)
{
	vector<vector<int> > ret;
	if(root == NULL)
		return ret;
	int height = getHeight(root);
	for(int i = 0; i < height; i++)
	{
		vector<int> vec;
		traverse(vec,root,i);
		ret.push_back(vec);
	}
	return ret;

}

