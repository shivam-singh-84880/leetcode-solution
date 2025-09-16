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
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;
        int n = lists.size();
        for(int i=0; i<n; i++){
            if(lists[i] != NULL){
                pq.push({lists[i]->val,lists[i]});
            }
        }
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        while(!pq.empty()){
            auto [num,temp] = pq.top();
            pq.pop();
            if(temp->next){
                pq.push({temp->next->val,temp->next});
            }
            curr->next = temp;
            curr = curr->next;
        }
        return head->next;
    }
};