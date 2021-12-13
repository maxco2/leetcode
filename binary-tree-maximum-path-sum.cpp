//
// @lc app=leetcode.cn id=198748903 lang=cpp
//
// [198748903] binary-tree-maximum-path-sum [二叉树中的最大路径和]
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
    int res;
    int dfs(TreeNode* t){
        if(!t) return 0;
        int left = max(dfs(t->left),0);
        int right = max(dfs(t->right),0);
        int cur=left+right+t->val;
        res=max(res,cur);
        return t->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        res=INT_MIN;
        dfs(root);
        return res;
    }
};
// @lc code=end