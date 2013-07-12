#define NULL 0
class ListNode{
public:
	ListNode(int v = 0) : val(v), next(NULL) {}
	int val;
	ListNode* next;

};

ListNode* insert(ListNode* head, const int& item)
{
	if(head == NULL)
	{
		ListNode* newNode = new ListNode(item);
		newNode->next = newNode;
		head = newNode;
		return head;
	}
	ListNode* prev = head;
	ListNode* current = head->next;
	while(current != head->next)
	{
		if(item >= prev->val && item <= current->val)
			break;
		if(prev->val > current->val && (item >= prev->val || item <= current->val))
			break;
		prev = current;
		current = current->next;

	}
	ListNode* newNode = new ListNode(item);
	newNode->next = current;
	prev->next = newNode;
	return head;

}

