//
// @lc app=leetcode.cn id=177462926 lang=cpp
//
// [177462926] ping-heng-er-cha-shu-lcof [平衡二叉树]
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
    int dfs(TreeNode* root){
        if(!root) return 0;
        int l=dfs(root->left);
        if(l==-1) return -1;
        int r=dfs(root->right);
        if(r==-1) return -1;
        if(r-l<=1&&l-r<=1) return max(l,r)+1;
        return -1;
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root)!=-1;
    }
};
// @lc code=end