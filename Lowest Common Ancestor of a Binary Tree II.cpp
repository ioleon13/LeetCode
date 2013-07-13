#include <iostream>
#include <set>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
	TreeNode* parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};


int getHeight(TreeNode* root, TreeNode* target)
{
	int height = 0;
	while(target != root)
	{
		height++;
		target = target->parent;
	}
	return height;
}

bool isIn(TreeNode* current, TreeNode* target)
{
	if(current == NULL)
		return false;
	if(current == target)
		return true;
	return isIn(current->left,target) || isIn(current->right,target);
}

TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if(root == NULL || p == NULL || q == NULL)
		return NULL;
	if(!isIn(root,p) || !isIn(root,q))
		return NULL;
	int pHeight = getHeight(root,p);
	int qHeight = getHeight(root,q);
	int dif = abs(pHeight - qHeight);
	if(pHeight > qHeight)
	{
		while(dif-- > 0)
			p = p->parent;
	}
	else
	{
		while(dif-- > 0)
			q = q->parent;
	}
	while(p != q)
	{
		p = p->parent;
		q = q->parent;
	}
	return p;
}


TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if(root == NULL || p == NULL || q == NULL)
		return NULL;
	if(!isIn(root,p) || !isIn(root,q))
		return NULL;
	set<TreeNode*> hash;
	while(p != NULL)
	{
		hash.insert(p);
		p = p->parent;
	}
	while(!hash.count(q))
		q = q->parent;
	return q;
}