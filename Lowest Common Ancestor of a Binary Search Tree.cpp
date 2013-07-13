#include <iostream>
using namespace std;

#define NULL 0
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

bool isIn(TreeNode* current, TreeNode* target)
{
	if(current == NULL)
		return false;
	if(current == target)
		return true;
	return isIn(current->left,target) || isIn(current->right,target);
}

TreeNode* findLCARec(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if(root->val > max(p->val,q->val) )
		return findLCARec(root->left,p,q);
	else if(p->val < min(p->val,q->val))
		return findLCARec(root->right,p,q);
	else return root;
}
TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if(root == NULL || p == NULL || q == NULL)
		return NULL;
	if(!isIn(root,p) || !isIn(root,q))
		return NULL;
	return findLCARec(root,p,q);
}

