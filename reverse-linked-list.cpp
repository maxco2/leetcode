//
// @lc app=leetcode.cn id=168789859 lang=cpp
//
// [168789859] reverse-linked-list [反转链表]
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