#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class GraphNode{
public:
	GraphNode(int d = 0) : data(d) {}
	int data;
	vector<GraphNode*> vec;
};

void cloneDFS(GraphNode* root, GraphNode*& dupRoot, map<GraphNode*, GraphNode*>& hash)
{
	if(root == NULL)
	{
		dupRoot = NULL;
		return;
	}
	if(hash.count(root))
	{
		dupRoot = hash[root];
		return;
	}
	hash.insert(make_pair(root,dupRoot));
	dupRoot = new GraphNode(root->data);
	vector<GraphNode*> vec = root->vec;
	int n = vec.size();
	root->vec = vector<GraphNode*>(n);
	for(int i = 0; i < n; i++)
		cloneDFS(vec[i],dupRoot->vec[i],hash);
}

GraphNode* cloneBFS(GraphNode* root)
{
	if(root == NULL)
		return NULL;
	GraphNode* dupRoot = new GraphNode(root->data);
	queue<GraphNode*> que;
	que.push(root);
	map<GraphNode*, GraphNode*> hash;
	hash.insert(make_pair(root,dupRoot));
	while(!que.empty())
	{
		GraphNode* top = que.front();
		que.pop();
		vector<GraphNode*> vec = top->vec;
		int n = vec.size();
		hash[top]->vec = vector<GraphNode*>(n);
		for(int i = 0; i < n; i++)
		{
			if(vec[i] == NULL)
				hash[top]->vec[i] = NULL;
			else
			{
				if(!hash.count(vec[i]))
				{
					hash[top]->vec[i] = new GraphNode(vec[i]->data);
					que.push(vec[i]);
					hash.insert(make_pair(vec[i],hash[top]->vec[i]));
				}
				else hash[top]->vec[i] = hash[vec[i]];
			}
		}
	}
	return dupRoot;
}


