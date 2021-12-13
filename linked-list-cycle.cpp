//
// @lc app=leetcode.cn id=170203700 lang=cpp
//
// [170203700] linked-list-cycle [环形链表]
//
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
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        auto slow=head;
        auto fast=head->next;
        while(slow&&fast){
            if(fast->next==NULL){
                return false;
            }
            if(slow==fast){
                return true;
            }
            slow=slow->next;
            fast=fast->next->next;
        }
        return false;
    }
};
// @lc code=end