//
// @lc app=leetcode.cn id=200690708 lang=cpp
//
// [200690708] linked-list-cycle-ii [环形链表 II]
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
        auto fast=head;
        auto slow=head;
        while(fast){
            if(!fast->next){
                return NULL;
            }
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
// @lc code=end