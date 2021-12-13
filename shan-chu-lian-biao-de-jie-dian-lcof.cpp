//
// @lc app=leetcode.cn id=179615701 lang=cpp
//
// [179615701] shan-chu-lian-biao-de-jie-dian-lcof [删除链表的节点]
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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val==val) return head->next;
        auto h=head;
        auto last=head;
        while(head){
            if(head->val==val){
                last->next=head->next;
                break;
            }
            last=head;
            head=head->next;
        }
        return h;

    }
};
// @lc code=end