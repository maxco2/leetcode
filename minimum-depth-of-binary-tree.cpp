//
// @lc app=leetcode.cn id=170212256 lang=cpp
//
// [170212256] minimum-depth-of-binary-tree [二叉树的最小深度]
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
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        int l=minDepth(root->left);
        int r=minDepth(root->right);
        if(l==0) return r+1;
        if(r==0) return l+1;
        return min(l,r)+1;
    }
};
// @lc code=end