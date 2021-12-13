//
// @lc app=leetcode.cn id=178826413 lang=cpp
//
// [178826413] er-cha-shu-de-jing-xiang-lcof [二叉树的镜像]
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root) return root;
        auto tmp=mirrorTree(root->right);
        root->right=mirrorTree(root->left);
        root->left=tmp;
        return root;
    }
};
// @lc code=end