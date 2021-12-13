//
// @lc app=leetcode.cn id=192772967 lang=cpp
//
// [192772967] er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof [二叉搜索树与双向链表]
//
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* prv,*head;
    void dfs(Node* t){
        if(!t) return;
        dfs(t->left);
        if(prv){
            prv->right=t;
            t->left=prv;
        }else{
            head=t;
        }
        prv=t;
        dfs(t->right);
    }
    Node* treeToDoublyList(Node* root) {
        if(!root) return NULL;
        prv=head=NULL;
        dfs(root);
        prv->right=head;
        head->left=prv;
        return head;
    }
};
// @lc code=end