//
// @lc app=leetcode.cn id=201470928 lang=cpp
//
// [201470928] merge-k-sorted-lists [合并K个升序链表]
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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        auto cmp=[](ListNode* a,ListNode* b){
            return a->val>b->val;
        };
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> q(cmp);
        for(auto l:lists){
            if(l)
            q.push(l);
        }
        ListNode* prev=nullptr;ListNode* head=nullptr;;
        while(!q.empty()){
            auto t=q.top();q.pop();
            if(!prev)
            prev=t,head=t;
            else
            prev->next=t,prev=t;
            if(t->next){
                q.push(t->next);
            }
        }
        return head;
    }
};
// @lc code=end