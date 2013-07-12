#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printLeftEdge(TreeNode* current, bool print)
{
	if(current == NULL)
		return;

	if( (current->left == NULL && current->right == NULL) || print)
		cout<<current->val;

	printLeftEdge(current->left,print);
	printLeftEdge(current->right,print && current->left ? false : true);

}

void printRightEdge(TreeNode* current, bool print)
{
	if(current == NULL)
		return;

	printRightEdge(current->left,print && current->right ? false : true);
	printRightEdge(current->right,print);

	if( (current->left == NULL && current->right == NULL) || print)
		cout<<current->val;

}

void printEdge(TreeNode* root)
{
	if(root == NULL)
		return;
	cout<<root->val;
	printLeftEdge(root->left,true);
	printRightEdge(root->right,true);
}

