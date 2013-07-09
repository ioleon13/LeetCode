
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
    vector<TreeNode*> generateTreesRec(int start, int end)
    {
        vector<TreeNode*> ret;
        if(start > end)
        {
            ret.push_back(NULL);
            return ret;
        }
        
        for(int k = start; k <= end; k++)
        {
            vector<TreeNode*> leftVec = generateTreesRec(start,k-1);
            vector<TreeNode*> rightVec = generateTreesRec(k+1,end);
            for(int i = 0; i < leftVec.size(); i++)
                for(int j = 0; j < rightVec.size(); j++)
                {
                    TreeNode* newNode = new TreeNode(k);
                    newNode->left = leftVec[i];
                    newNode->right = rightVec[j];
                    ret.push_back(newNode);
                }
        }
        return ret;
    
    }
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return generateTreesRec(1,n);
        
        
    }
};