//
// @lc app=leetcode.cn id=213029916 lang=cpp
//
// [213029916] reverse-nodes-in-k-group [K 个一组翻转链表]
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
    pair<ListNode*,ListNode*> reverse(ListNode* h, ListNode* t){
        ListNode* pre=t->next;
        ListNode* cur=h;
        while(pre!=t){
            auto tmp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=tmp;
        }
        return {t,h};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode fake=ListNode(-1);
        ListNode* hair=&fake;
        hair->next=head;
        auto pre=hair;
        while(head){
            auto tail=pre;
            for(int i=0;i<k;++i){
                tail=tail->next;
                if(!tail){
                    return hair->next;
                }
            }
            ListNode* nex=tail->next;
            tie(head,tail)=reverse(head,tail);
            pre->next=head;
            tail->next=nex;
            head=nex;
            pre=tail;
        }
        return hair->next;
    }
};
// @lc code=end