
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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL)
            return head;
        ListNode* current = head;
        int len = 1;
        while(current->next != NULL)
        {
            current = current->next;
            len++;
        }
        current->next = head;
        int steps = len - k % len;
        while(steps-- > 0)
            current = current->next;
        head = current->next;
        current->next = NULL;
        return head;
    }
};
