//
// @lc app=leetcode.cn id=194632512 lang=cpp
//
// [194632512] validate-binary-search-tree [验证二叉搜索树]
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
    long long last;
    bool dfs(TreeNode* t){
        if(!t) return true;
        if(dfs(t->left)){
            if(last<t->val){
                last=t->val;
                if(dfs(t->right)){
                    return true;
                }
            }
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        last=LONG_MIN;
        return dfs(root);
    }
};
// @lc code=end