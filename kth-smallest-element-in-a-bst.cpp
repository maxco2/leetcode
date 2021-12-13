//
// @lc app=leetcode.cn id=172646954 lang=cpp
//
// [172646954] kth-smallest-element-in-a-bst [二叉搜索树中第K小的元素]
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
    int ret;
    int dfs(TreeNode* root,int k,int n){
        if(!root) return n;
        int l=dfs(root->left,k,n);
        if(l+1==k) {ret=root->val;return l+1;}
        return dfs(root->right,k,l+1);

    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k,0);
        return ret;
    }
};
// @lc code=end