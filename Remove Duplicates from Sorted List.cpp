
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* prev = head;
        ListNode* current = head->next;
        while(current != NULL)
        {
            if(prev->val == current->val)
            {
                ListNode* tem = current;
                current = current->next;
                prev->next = current;
                delete tem;       
            }
            else 
            {
                prev = current;
                current = current->next;
            }
        }
        return head;
    }
};