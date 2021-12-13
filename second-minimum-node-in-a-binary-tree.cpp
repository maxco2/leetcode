//
// @lc app=leetcode.cn id=200277624 lang=cpp
//
// [200277624] second-minimum-node-in-a-binary-tree [二叉树中第二小的节点]
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
    long long m;
    void dfs(TreeNode* t){
        if(!t) return;
        if(m==-1) m=t->val;
        m=min(m,(long long)t->val);
        if(t->left){
            dfs(t->left);
            dfs(t->right);
        }
    }
    long long n;
    void dfs2(TreeNode* t){
        if(!t) return;
        if(t->val>m&&n==-1) n=t->val;
        if(t->val>m) n=min(n,(long long)t->val);
        if(t->left){
            dfs2(t->left);
            dfs2(t->right);
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        m=-1;n=-1;
        dfs(root);
        dfs2(root);
        return n;
    }
};
// @lc code=end