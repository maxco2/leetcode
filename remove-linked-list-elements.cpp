//
// @lc app=leetcode.cn id=185929786 lang=cpp
//
// [185929786] remove-linked-list-elements [移除链表元素]
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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        if(head->val==val) return removeElements(head->next,val);
        auto h=head;
        while(h){
            if(h->next&&h->next->val==val){
                auto tmp=h->next->next;
                while(tmp&&tmp->val==val){
                    tmp=tmp->next;
                }
                h->next=tmp;
            }
            h=h->next;
        }
        return head;
    }
};
// @lc code=end