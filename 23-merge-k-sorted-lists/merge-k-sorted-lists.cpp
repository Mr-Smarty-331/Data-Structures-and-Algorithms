/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<>> pq;

        for (auto it : lists) { 
            while(it!=nullptr) {
                pq.push(it->val);
                it = it->next;
            }
        }
        if (pq.empty()) return nullptr;

        ListNode *ans = new ListNode(pq.top());

        pq.pop();
        ListNode *temp = ans;
        while(!pq.empty()){
            temp->next = new ListNode(pq.top());
            pq.pop();
            temp = temp->next;
     
        }

        return ans;
    }
};