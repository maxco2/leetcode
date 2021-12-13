//
// @lc app=leetcode.cn id=203749850 lang=cpp
//
// [203749850] cong-wei-dao-tou-da-yin-lian-biao-lcof [从尾到头打印链表]
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
    vector<int> reversePrint(ListNode* head) {
        vector<int> ret;
        while(head){
            ret.push_back(head->val);
            head=head->next;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
// @lc code=end