
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* dummy = new ListNode(0);
        ListNode* last = dummy;
        while(l1 != NULL || l2 != NULL)
        {
            int val1 = l1 == NULL ? INT_MAX : l1->val;
            int val2 = l2 == NULL ? INT_MAX : l2->val;
            ListNode* tem;
            if(val1 < val2)
            {
                tem = l1;
                l1 = l1->next;
            }
            else 
            {
                tem = l2;
                l2 = l2->next;
            }
            tem->next = NULL;
            last->next = tem;
            last = last->next;
        
        }
        return dummy->next;
    }
};
