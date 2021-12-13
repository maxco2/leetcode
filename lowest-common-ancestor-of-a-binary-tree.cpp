//
// @lc app=leetcode.cn id=192058942 lang=cpp
//
// [192058942] lowest-common-ancestor-of-a-binary-tree [二叉树的最近公共祖先]
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
    unordered_map<TreeNode*,pair<TreeNode*,int>> fa;
    void dfs(TreeNode* t,TreeNode* tfa,int d){
        if(!t) return;
        fa[t]={tfa,d};
        dfs(t->left,t,d+1);
        dfs(t->right,t,d+1);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fa.clear();
        dfs(root,NULL,1);
        while(fa[p].second>fa[q].second) p=fa[p].first;
        while(fa[q].second>fa[p].second) q=fa[q].first;
        while(p!=q){
            p=fa[p].first;
            q=fa[q].first;
        }
        return p;
    }
};
// @lc code=end