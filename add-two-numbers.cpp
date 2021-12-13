//
// @lc app=leetcode.cn id=168789694 lang=cpp
//
// [168789694] add-two-numbers [两数相加]
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto st1=l1;
        auto st2=l2;
        ListNode* l3=new ListNode(0);
        auto res=l3;
        int ci=0;
        auto addNode=[](ListNode* l3,int v,bool create=true)
        {
           if(!l3)
           l3=new ListNode(v);
            else l3->val=v;
            if(create)
            {l3->next=new ListNode(0);
           return l3->next;}
            return l3;
        };
        while(st1&&st2)
        {
            int tmp=st1->val+st2->val+ci;
            ci=tmp/10;
            st1=st1->next;
            st2=st2->next;
            //cout<<tmp<<endl;
            l3=addNode(l3,tmp%10,st1||st2);
        }
        while(st1)
        {
            int tmp=st1->val+ci;
            ci=(st1->val+ci)/10;
            st1=st1->next;
            l3=addNode(l3,tmp%10,st1);
        }
        while(st2)
        {
            int tmp=st2->val+ci;
            ci=(st2->val+ci)/10;
            st2=st2->next;
            l3=addNode(l3,tmp%10,st2);
        }
       if(ci==1)  l3->next=new ListNode(ci);
        return res;  
        
    }
};
// @lc code=end