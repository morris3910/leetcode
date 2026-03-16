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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        ListNode* rev = head;
        std::stack<int> nums;
        int count = 0;
        while(cur){
            nums.push(cur->val);
            count++;
            if(!(count%k)){
                for(int i=0; i<k; i++){
                    rev->val = nums.top();
                    nums.pop();
                    rev = rev->next;
                }
            }
            cur = cur->next;
        }
        return head;
    }
};