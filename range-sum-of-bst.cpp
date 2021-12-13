//
// @lc app=leetcode.cn id=172610525 lang=cpp
//
// [172610525] range-sum-of-bst [二叉搜索树的范围和]
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
    int sum;
    int low;
    int high;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        if(root->val>=low&&root->val<=high){
            sum+=root->val;
        }
        dfs(root->right);
    }
    int rangeSumBST(TreeNode* root, int l, int h) {
        sum=0;
        low=l;
        high=h;
        dfs(root);
        return sum;
    }
};
// @lc code=end