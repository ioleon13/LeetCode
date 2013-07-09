
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    TreeLinkNode* getNext(TreeLinkNode* current)
    {
    
        while(current != NULL)
        {
            if(current->left != NULL)
                return current->left;
            if(current->right != NULL)
                return current->right;
            current = current->next;
        }
        return NULL;
    
    }
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return;
        TreeLinkNode* current = root;
        TreeLinkNode* lead = root;
        TreeLinkNode* prev = NULL;
        while(current != NULL)
        {
            if(current->left != NULL)
            {
                if(prev == NULL)
                    prev = current->left;
                else 
                {
                    prev->next = current->left;
                    prev = prev->next;
                }
            
            }   
            if(current->right != NULL)
            {
                if(prev == NULL)
                    prev = current->right;
                else 
                {
                    prev->next = current->right;
                    prev = prev->next;
                }
            } 
            if(current->next != NULL)
                current = current->next;
            else
            {
                current = getNext(lead);
                lead = current;
                prev = NULL;
            }
        }
        
    }
};