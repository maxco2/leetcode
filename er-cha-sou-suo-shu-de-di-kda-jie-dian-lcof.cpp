//
// @lc app=leetcode.cn id=177460319 lang=cpp
//
// [177460319] er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof [二叉搜索树的第k大节点]
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
    int count;
    int dfs(TreeNode* t,int k){
        if(t){
            int r=dfs(t->right,k);
            if(r!=-1) return r;
            count+=1;
            if(count==k){
                return t->val;
            }
            int l=dfs(t->left,k);
            if(l!=-1) return l;
        }
        return -1;
    }
    int kthLargest(TreeNode* root, int k) {
        count=0;
        return dfs(root,k);
    }
};
// @lc code=end