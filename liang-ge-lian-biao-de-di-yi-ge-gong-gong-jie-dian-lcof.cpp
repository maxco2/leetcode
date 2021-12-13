//
// @lc app=leetcode.cn id=198096389 lang=cpp
//
// [198096389] liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof [两个链表的第一个公共节点]
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headB&&headA) return NULL;
        if(!headA&&headB) return NULL;
        auto h1=headA;
        auto h2=headB;
        while(h1!=h2){
            h1=h1?h1->next:headB;
            h2=h2?h2->next:headA;
        }   
        return h1;
    }
};
// @lc code=end