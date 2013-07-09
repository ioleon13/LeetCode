

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* dummy = new ListNode(0);
        ListNode* last = dummy;
        int carry = 0;
        while(l1 != NULL || l2 != NULL)
        {
            int digit1 = l1 == NULL ? 0 : l1->val;
            int digit2 = l2 == NULL ? 0 : l2->val;
            int total = digit1 + digit2 + carry;
            last->next = new ListNode(total % 10);
            last = last->next;
            carry = total / 10;
            if(l1 != NULL)
                l1 = l1->next;
            if(l2 != NULL)
                l2 = l2->next;
        }
        if(carry)
            last->next = new ListNode(carry);
        return dummy->next;
    }
};

