//
// @lc app=leetcode.cn id=192059148 lang=cpp
//
// [192059148] palindrome-linked-list [回文链表]
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
    ListNode* reverse(ListNode* h){
        ListNode* prev=nullptr;
        ListNode* curr=h;
        while(curr){
            auto nexttmp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nexttmp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(!head||head->next==nullptr) return true;
        auto fast=head;
        auto slow=head;
        while(fast&&slow){
            if(fast&&fast->next){
                fast=fast->next->next;
                slow=slow->next;
            }else{
                break;
            }
        }
        slow=reverse(slow);
        bool res=true;
        while(head&&slow){
            if(head->val!=slow->val){
                return false;
            }else{
                head=head->next;
                slow=slow->next;
            }
        }
        return true;

    }
};
// @lc code=end