//
// @lc app=leetcode.cn id=176920106 lang=cpp
//
// [176920106] swap-nodes-in-pairs [两两交换链表中的节点]
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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return nullptr;
        if(head->next!=nullptr){
            auto nn=head->next->next;
            auto tmp=head;
            head=head->next;
            head->next=tmp;
            tmp->next=swapPairs(nn);
        }
        return head;
    }
};
// @lc code=end