//
// @lc app=leetcode.cn id=186223833 lang=cpp
//
// [186223833] linked-list-cycle-lcci [环路检测]
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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        if(!head->next) return NULL;
        auto fast=head;
        auto slow=head;
        while(fast&&slow){
            if(fast->next)
            fast=fast->next->next;
            else
            return NULL;
            slow=slow->next;
            if(fast==slow){
            auto p=head;
            while(p!=slow){
                p=p->next;
                slow=slow->next;
            }
            return p;
        }
        }
        
        return NULL;
    }
};
// @lc code=end