#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    static bool cmp(ListNode* x, ListNode* y){
        return (x->val < y->val);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (vector<ListNode *>::iterator it = lists.begin(); it != lists.end();){
            if(!*it){
                lists.erase(it);
                continue;
            }
            it++;
        }
        
        ListNode *h, *tmp;
        h = tmp = new ListNode(-1, nullptr);
        sort(lists.begin(), lists.end(), cmp);
        while(lists.size() > 0){
            tmp->next = lists[0];
            tmp = tmp->next;
            lists[0] = lists[0]->next;
            if(!lists[0]){
                lists.erase(lists.begin());
            }
            else{
                // binary insertion sort
                unsigned int left = 1, right = lists.size() - 1;
                unsigned int ans = lists.size();
                unsigned int mid;
                while(left <= right){
                    mid = (left + right) / 2;
                    if(lists[mid]->val > lists[0]->val){
                        ans = mid;
                        right = mid - 1;
                    }
                    else{
                        left = mid + 1;
                    }
                }
                vector<ListNode *>::iterator it = lists.begin();
                for (unsigned int i = 0; i < ans; i++)
                    it++;
                lists.insert(it, lists[0]);
                lists.erase(lists.begin());
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

    ListNode * ans = s.mergeKLists(lists);
    while(ans){
        cout << ans->val;
        ans = ans->next;
    }
    return 0;
}