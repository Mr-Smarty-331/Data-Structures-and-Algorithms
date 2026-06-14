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
    int pairSum(ListNode* head) {
        ListNode* n1 = head;
        ListNode* n2 = head;
        int i = 0;
        vector<int> arr;
        int n;
        int mx = 0;
        while(n1){
            if(n2){
                arr.push_back(n1->val);
                n1 = n1->next;
                n2 = n2->next->next;
            }
            else{
                n = arr.size();
                // we reached mid and beyond
                arr[n-1-i]+=n1->val;
                mx = max(mx,arr[n-1-i]);
                n1=n1->next;
                i++;
            }

        }
        return mx;
    }
};