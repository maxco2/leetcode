//
// @lc app=leetcode.cn id=177940706 lang=cpp
//
// [177940706] invert-binary-tree [翻转二叉树]
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        auto tmp=invertTree(root->right);
        root->right=invertTree(root->left);
        root->left=tmp;
        return root;
    }
};
// @lc code=end