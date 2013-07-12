#define NULL 0
class CNode{
public:
	CNode(int v = 0) : val(v), next(NULL) {}
	int val;
	CNode* next;

};

CNode* insert(CNode* head, const int& item)
{
	if(head == NULL)
	{
		CNode* newNode = new CNode(item);
		newNode->next = newNode;
		head = newNode;
		return head;
	}
	CNode* prev = head;
	CNode* current = head->next;
	while(current != head->next)
	{
		if(item >= prev->val && item <= current->val)
			break;
		if(prev->val > current->val && (item >= prev->val || item <= current->val))
			break;
		prev = current;
		current = current->next;

	}
	CNode* newNode = new CNode(item);
	newNode->next = current;
	prev->next = newNode;
	return head;

}

