//
// @lc app=leetcode.cn id=163753614 lang=cpp
//
// [163753614] construct-binary-tree-from-preorder-and-inorder-traversal [从前序与中序遍历序列构造二叉树]
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bt(vector<int>& p,int lp,int rp,vector<int>& i,int li,int ri)
    {
        if(rp<=lp||lp>=p.size()) return nullptr;
        TreeNode* t=new TreeNode(p[lp]);
        //printf("lp:%d,rp:%d,li:%d,ri:%d,new root:%d\n",lp,rp,li,ri,p[lp]);
        int pli=li;
        for(;li<ri;++li) if(i[li]==p[lp]) break;
        if(li-pli!=0){
            //printf("bleft,li:%d,pli:%d,ri:%d\n",li,pli,ri);
            t->left=bt(p,lp+1,lp+1+li-pli,i,pli,li);
        }
        if(li+1!=ri){
            t->right=bt(p,lp+1+li-pli,rp,i,li+1,ri);            
        } 
        return t;
    }
    TreeNode* buildTree(vector<int>& p, vector<int>& i) {
        return bt(p,0,p.size(),i,0,i.size());
    }
};
// @lc code=end