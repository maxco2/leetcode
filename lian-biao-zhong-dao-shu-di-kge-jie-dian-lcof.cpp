//
// @lc app=leetcode.cn id=214190677 lang=cpp
//
// [214190677] lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof [链表中倒数第k个节点]
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        auto h=head;
        auto f=head;
        for(int i=0;i<k;++i){
            f=f->next;
        }
        while(f){
            h=h->next;
            f=f->next;
        }
        return h;
    }
};
// @lc code=end