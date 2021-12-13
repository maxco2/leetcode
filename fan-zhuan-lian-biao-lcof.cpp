//
// @lc app=leetcode.cn id=177921088 lang=cpp
//
// [177921088] fan-zhuan-lian-biao-lcof [反转链表]
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
    ListNode* reverseList(ListNode* head) {
if(head==nullptr) return head;
        ListNode* p=nullptr;
        auto c=head;
        auto n=head->next;
        while(c!=nullptr){
            c->next=p;
            p=c;
            c=n;
            if(n)
                n=n->next;
            else
                n=nullptr;
        }
        return p;     
    }
};
// @lc code=end