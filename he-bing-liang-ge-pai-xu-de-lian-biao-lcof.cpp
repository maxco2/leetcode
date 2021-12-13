//
// @lc app=leetcode.cn id=178825825 lang=cpp
//
// [178825825] he-bing-liang-ge-pai-xu-de-lian-biao-lcof [合并两个排序的链表]
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1&&!l2) return nullptr;
        if(l1&&!l2) return l1;
        if(l2&&!l1) return l2;
        auto first=true;
        ListNode* h=nullptr;
        ListNode* cur=nullptr;
        while(l1&&l2){
            ListNode* m=NULL;
            if(l1->val<=l2->val){
                m=l1;
                l1=l1->next;
                m->next=nullptr;
            }else{
                m=l2;
                l2=l2->next;
                m->next=nullptr;
            }
            if(cur) {
                cur->next=m;
                cur=m;
            }
            if(first) h=cur=m,first=false;
        }
        if(l1) cur->next=l1;
        if(l2) cur->next=l2;
        return h;

    }
};
// @lc code=end