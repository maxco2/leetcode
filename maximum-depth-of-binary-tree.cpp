//
// @lc app=leetcode.cn id=177461096 lang=cpp
//
// [177461096] maximum-depth-of-binary-tree [二叉树的最大深度]
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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int l=maxDepth(root->left);
        int r=maxDepth(root->right);
        return max(l,r)+1;
    }
};
// @lc code=end