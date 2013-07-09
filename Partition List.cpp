
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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL)
            return NULL;
        ListNode* smallHead = new ListNode(0);
        ListNode* smallLast = smallHead;
        ListNode* largeHead = new ListNode(0);
        ListNode* largeLast = largeHead;
        ListNode* current = head;
        while(current != NULL)
        {
            ListNode* tem = current;
            current = current->next;
            tem->next = NULL;
            if(tem->val < x)
            {
                smallLast->next = tem;
                smallLast = smallLast->next;
            }
            else 
            {
                largeLast->next = tem;
                largeLast = largeLast->next;
            }
        }
        smallLast->next = largeHead->next;
        return smallHead->next;
    }
};