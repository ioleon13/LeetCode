
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* convert(ListNode*& current, int start, int end)
    {
        if(start > end)
            return NULL;
        int mid = start + (end-start) / 2;
        TreeNode* left = convert(current,start,mid-1);
        TreeNode* parent = new TreeNode(current->val);
        parent->left = left;
        current = current->next;
        parent->right = convert(current,mid+1,end);
        return parent;
    
    
    }
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL)
            return NULL;
        int len = 0;
        ListNode* current = head;
        while(current != NULL)
        {
            current = current->next;
            len++;
        }
        return convert(head,0,len-1);
    }
};