//
// @lc app=leetcode.cn id=192784402 lang=cpp
//
// [192784402] er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof [二叉搜索树的最近公共祖先]
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
    bool dfs(TreeNode* t,TreeNode* p,TreeNode* q){
        if(!t) return false;
        bool lson=dfs(t->left,p,q);
        bool rson=dfs(t->right,p,q);
        if((lson&&rson)||((t==p||t==q)&&(lson||rson))) ans=t;
        return lson||rson||(t==p||t==q);
    }
    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans=NULL;
        dfs(root,p,q);
        return ans;
    }
};
// @lc code=end