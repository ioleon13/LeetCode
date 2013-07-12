void splitList(ListNode* head, ListNode*& front, ListNode*& back)
{
	if(head == NULL)
		return;
	ListNode* slow = head;
	ListNode* fast = head;
	while(fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	front = head;
	back = slow->next;
	slow->next = NULL;
}