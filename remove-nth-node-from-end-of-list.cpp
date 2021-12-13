//
// @lc app=leetcode.cn id=195349936 lang=cpp
//
// [195349936] remove-nth-node-from-end-of-list [删除链表的倒数第 N 个结点]
//
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto slow=head;
        auto fast=head;
        for(int i=0;i<n;++i) fast=fast->next;
        if(!fast) return slow->next;
        while(fast){
            if(!fast->next) break;
            fast=fast->next;
            slow=slow->next;
        }
        if(n==1) slow->next=nullptr;
        else slow->next=slow->next->next;
        return head;
    }
};
// @lc code=end