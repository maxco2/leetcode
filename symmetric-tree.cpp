//
// @lc app=leetcode.cn id=178737268 lang=cpp
//
// [178737268] symmetric-tree [对称二叉树]
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
    TreeNode* rev(TreeNode* t){
        if(!t) return nullptr;
        auto tmp=t->right;
        t->right=rev(t->left);
        t->left=rev(tmp);
        return t;
    }
    bool eq(TreeNode* a,TreeNode* b){
        if(!a&&!b) return true;
        if(a&&b&&a->val==b->val){
            bool left=eq(a->left,b->left);
            if(!left) return false;
            bool right=eq(a->right,b->right);
            if(!right) return false;
            return true;
        }
        return false;
    }
    bool isSymmetric(TreeNode* t) {
        if(!t) return true;
        if(!t->left&&!t->right){
            return true;
        }
        if(t->left&&t->right){
            auto l=rev(t->left);
            return eq(l,t->right);
        }
        return false;

    }
};
// @lc code=end