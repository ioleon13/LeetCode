
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL || n <= 0)
            return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* current = dummy;
        while(n-- > 0)
            current = current->next;
        while(current->next != NULL)
        {
            current = current->next;
            prev = prev->next;
        }
        ListNode* tem = prev->next;
        prev->next = tem->next;
        delete tem;
        return dummy->next;
    }
};
