#include <iostream>
#include <fstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void serialize(ofstream& outfile, TreeNode* current)
{
	if(current == NULL)
	{
		outfile<<'#';
		return;
	}
	outfile<<current->val;
	serialize(outfile,current->left);
	serialize(outfile,current->right);
}

void deserialize(ifstream& infile, TreeNode*& current)
{
	char ch;
	infile>>ch;
	if(ch == '#')
		return;
	current = new TreeNode(current->val);
	deserialize(infile,current->left);
	deserialize(infile,current->right);
}

