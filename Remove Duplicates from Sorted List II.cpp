

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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* p = head;
        ListNode* q = head->next;
        while(q != NULL)
        {
            if(p->val == q->val)
            {
                while(q != NULL && q->val == p->val)
                    q = q->next;
                prev->next = q;
                if(q == NULL)
                    return dummy->next;
                p = q;
                q = q->next;
            }
            else
            {
                prev = p;
                p = q;
                q = q->next;
            }
  
        }
        return dummy->next;
    }
};
