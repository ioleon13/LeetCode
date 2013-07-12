void reverse(ListNode*& head)
{
	if(head == NULL)
		return;
	ListNode* prev = NULL;
	ListNode* current = head;
	while(current != NULL)
	{
		ListNode* tem = current->next;
		current->next = prev;
		prev = current;
		current = tem;
	}
	head = prev;
}



void reverseRec(ListNode*& current)
{
	if(current == NULL)
		return;
	ListNode* rest = current->next;
	if(rest == NULL)
		return;
	reverseRec(rest);
	current->next->next = current;
	current->next = NULL;
	current = rest;

}