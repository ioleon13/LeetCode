
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
     typedef pair<int,int> Pair; //idx,val
	 struct cmp{
		bool operator()(const Pair& left, const Pair& right)
		{
			return left.second > right.second;
		}
	 };
     ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(lists.empty())
            return NULL;
        int n = lists.size();
        priority_queue<Pair,vector<Pair>,cmp> minHeap;
        for(int i = 0; i < n; i++)
        {
            if(lists[i] != NULL)
            {
                minHeap.push(make_pair(i,lists[i]->val));
                lists[i] = lists[i]->next;
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* last = dummy;
        while(!minHeap.empty())
        {    
            Pair top = minHeap.top();
            minHeap.pop();
            int idx = top.first;
            int val = top.second;
            last->next = new ListNode(val);
            last = last->next;
            if(lists[idx] != NULL)
            {
                minHeap.push(make_pair(idx,lists[idx]->val));
                lists[idx] = lists[idx]->next;
            }
        }
        return dummy->next;
    }
};