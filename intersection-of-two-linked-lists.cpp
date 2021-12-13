//
// @lc app=leetcode.cn id=178745758 lang=cpp
//
// [178745758] intersection-of-two-linked-lists [相交链表]
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
        auto sta=headA;
        auto stb=headB;
        while(headA!=headB){
            headB=headB?headB->next:sta;
            headA=headA?headA->next:stb;
        }
        return headB;
    }
};
// @lc code=end