//
// @lc app=leetcode.cn id=190884049 lang=cpp
//
// [190884049] diameter-of-binary-tree [二叉树的直径]
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
    int d;
    int depth(TreeNode* t){
        if(!t) return 0;
        int l=depth(t->left);
        int r=depth(t->right);
        d=max(d,l+r);
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        d=0;
        depth(root);
        return d;
    }
};
// @lc code=end