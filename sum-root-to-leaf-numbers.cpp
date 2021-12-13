//
// @lc app=leetcode.cn id=177414629 lang=cpp
//
// [177414629] sum-root-to-leaf-numbers [求根节点到叶节点数字之和]
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
    int sumNumbers(TreeNode* root,int cur){
        if(!root) return 0;
        cur=cur*10+root->val;
        if(root->left||root->right){
        int l=sumNumbers(root->left,cur);
        int r=sumNumbers(root->right,cur);
        return l+r;
        }
        return cur;
    }
    int sumNumbers(TreeNode* root) {
        return sumNumbers(root,0);
    }
};
// @lc code=end