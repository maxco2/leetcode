//
// @lc app=leetcode.cn id=168789857 lang=cpp
//
// [168789857] delete-node-in-a-linked-list [删除链表中的节点]
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
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        //auto tmp=node->next;
        node->next=node->next->next;
        //free(tmp);
    }
};
// @lc code=end