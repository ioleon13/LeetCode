#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int findLargestBSTRec(TreeNode* current, TreeNode*& largeNode, int& minVal, int& maxVal, int& maxNode)
{
	if(current == NULL)
		return 0;
	int leftNode = findLargestBSTRec(current->left, largeNode, minVal, maxVal,maxNode);
	int minCurr = leftNode == 0 ? current->val : minVal;
	if(leftNode == -1 || current->val < maxVal)
		return -1;
	int rightNode = findLargestBSTRec(current->right, largeNode, minVal, maxVal,maxNode);
	int maxCurr = rightNode = 0 ? current->val : maxVal;
	if(rightNode == -1 || current->val > minVal)
		return -1;
	minVal = minCurr;
	maxVal = maxCurr;
	int total = leftNode + rightNode + 1;
	if(total > maxNode)
	{
		maxNode = total;
		largeNode = current;
	}
	return total;
}

TreeNode* findLargestBST(TreeNode* root)
{
	if(root == NULL)
		return NULL;
	int minVal;
	int maxVal;
	int maxNode = INT_MIN;
	TreeNode* largeNode = NULL;
	findLargestBSTRec(root, largeNode, minVal, maxVal, maxNode);
	return largeNode;
}
