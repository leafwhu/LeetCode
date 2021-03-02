# include<cstdio>
# include<iostream>

using namespace std;

 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* l){
	ListNode *tmp = l;
	printf("%d ", l->val);
	while(tmp->next){
		tmp = tmp->next;
		printf("%d ", tmp->val);
	}
	printf("\n");
}

 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *merged, *tmp, *tmp1, *tmp2;
        
		tmp1 = l1;
        tmp2 = l2;
		merged = new ListNode();
		tmp = merged;
		while(tmp1 && tmp2){
			if(tmp1->val < tmp2->val){
				tmp->next = tmp1;
				tmp1 = tmp1->next;
				tmp = tmp->next;
			}
			else{
				tmp->next = tmp2;
				tmp2 = tmp2->next;
				tmp = tmp->next; 
			}
		}
		if(tmp1){
			tmp->next = tmp1;
		}
		if(tmp2){
			tmp->next = tmp2;
		}
		return merged->next;
    }
};

int main()
{
	ListNode l12{2};
	ListNode l11{1, &l12};
	printList(&l11);
	
	ListNode l22{3};
	ListNode l21{0, &l22};
	printList(&l21);
	
	Solution* sol = new Solution();
	ListNode *ans = sol->	mergeTwoLists(&l11, &l21);
	printList(ans);
	
	
	return 0;
}