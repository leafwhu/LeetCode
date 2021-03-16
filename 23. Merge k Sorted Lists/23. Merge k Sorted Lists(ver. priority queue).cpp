#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    struct cmpListNode{
        bool operator() (ListNode *a, ListNode *b){
            if(!a)
                return false;
            if(!b)
                return true;
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *h, *tmp, *tmp2;
        h = tmp = new ListNode(-1, nullptr);
        priority_queue<ListNode *, vector<ListNode *>, cmpListNode> q;
        for (ListNode *&list : lists){
            q.push(list);
        }
        while(!q.empty()){
            if(q.top()){
                tmp2 = q.top();
                q.pop();
                tmp->next = tmp2;
                tmp = tmp->next;
                tmp2 = tmp2->next;
                q.push(tmp2);
            }
            else{
                q.pop();
            }
        }
        return h->next;
    }
};


int main(){
    Solution s;

    ListNode *l3 = new ListNode(5);
    ListNode *l2 = new ListNode(4, l3);
    ListNode *l1 = new ListNode(1, l2);

    ListNode *l6 = new ListNode(4);
    ListNode *l5 = new ListNode(3, l6);
    ListNode *l4 = new ListNode(1, l5);

    
    ListNode *l8 = new ListNode(6);
    ListNode *l7 = new ListNode(2, l8);

    vector<ListNode *> lists;
    lists.push_back(l1);
    lists.push_back(l4);
    lists.push_back(l7);
    lists.push_back(nullptr);
    lists.push_back(nullptr);
    lists.push_back(nullptr);

    ListNode * ans = s.mergeKLists(lists);
    while(ans){
        cout << ans->val;
        ans = ans->next;
    }
    return 0;
}