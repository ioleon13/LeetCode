
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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* current = head;
        ListNode* last = head->next;
        while(last != NULL)
        {
            ListNode* tem = last->next;
            prev->next = last;
            last->next = current;
            current->next = tem;
            if(tem == NULL)
                return dummy->next;
            prev = current;
            current = tem;
            last = tem->next;
        }
        return dummy->next;
    }
};
