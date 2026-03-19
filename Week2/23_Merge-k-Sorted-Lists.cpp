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
        if(lists.empty()) return NULL;
        if(lists.size() == 1) return lists[0];

        std::priority_queue<int, vector<int>, greater<>> pq;
        for(int i=0; i<lists.size(); i++){
            ListNode* cur = lists[i];
            while(cur != NULL){
                pq.push(cur->val);
                cur = cur->next;
            }
        }

        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        
        while(!pq.empty()){
            cur->next = new ListNode(pq.top());
            pq.pop();
            cur = cur->next;
        }

        return dummy->next;
    }
};