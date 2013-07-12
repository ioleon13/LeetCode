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
	if(current->val == target->val)
		return true;
	return isIn(current->left,target) || isIn(current->right,target);
}


//top-down
TreeNode* findLCARec(TreeNode* current, TreeNode* p, TreeNode* q)
{
	if(current == p || current == q)
		return current;
	bool pInLeft = isIn(current->left,p);
	bool qInLeft = isIn(current->left,q);
	if(pInLeft != qInLeft)
		return current;
	return pInLeft ? findLCARec(current->left,p,q) : findLCARec(current->right,p,q);

}

//bottom-up
TreeNode* findLCARec(TreeNode* current, TreeNode* p, TreeNode* q)
{
	if(current == NULL)
		return NULL;
	if(current == p || current == q)
		return current;
	TreeNode* left = findLCARec(current->left,p,q);
	TreeNode* right = findLCARec(current->right,p,q);
	if(left && right) 
		return current;
	return left ? left : right;
}



TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if(root == NULL || p == NULL || q == NULL)
		return NULL;
	if(!isIn(root,p) || !isIn(root,q))
		return NULL;
	return findLCARec(root,p,q);
}


