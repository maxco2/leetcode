//
// @lc app=leetcode.cn id=178753565 lang=cpp
//
// [178753565] fu-za-lian-biao-de-fu-zhi-lcof [复杂链表的复制]
//
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* h) {
        if(!h) return h;
        unordered_map<Node*,int> f1;
        vector<Node*> f2;
        Node* head=NULL;
        auto first=true;
        int idx=0;
        Node* last=NULL;
        auto oh=h;
        while(h){
            auto cur=new Node(h->val);
            if(last) last->next=cur;
            if(first) head=cur,first=false;
            f1.insert({h,idx++});
            f2.push_back(cur);
            last=cur;
            h=h->next;
        }
        h=oh;
        auto nh=head;
        while(h){
            if(h->random!=NULL)
            nh->random=f2[f1[h->random]];
            nh=nh->next;
            h=h->next;
        }
        return head;

        
    }
};

// @lc code=end