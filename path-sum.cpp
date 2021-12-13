//
// @lc app=leetcode.cn id=177405459 lang=cpp
//
// [177405459] path-sum [路径总和]
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
    bool dfs(TreeNode* t,int targetSum){
        if(t){
            if(t->val==targetSum&&!t->left&&!t->right){
                return true;
            }
            targetSum-=t->val;
            if(t->left){
                if(dfs(t->left,targetSum)){
                    return true;
                }
            }
            if(t->right){
                if(dfs(t->right,targetSum)){
                    return true;
                }
            }
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)
            return false;
        return dfs(root,targetSum);
    }
};
// @lc code=end