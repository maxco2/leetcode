//
// @lc app=leetcode.cn id=178733736 lang=cpp
//
// [178733736] binary-tree-inorder-traversal [二叉树的中序遍历]
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
    vector<int> ret;
    void dfs(TreeNode* t){
        if(!t) return;
        dfs(t->left);
        ret.push_back(t->val);
        dfs(t->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        ret.clear();
        dfs(root);
        return ret;

    }
};
// @lc code=end