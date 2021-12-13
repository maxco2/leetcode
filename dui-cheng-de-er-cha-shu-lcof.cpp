//
// @lc app=leetcode.cn id=179158622 lang=cpp
//
// [179158622] dui-cheng-de-er-cha-shu-lcof [对称的二叉树]
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
    bool isSymmetric(TreeNode* r1,TreeNode* r2){
        if(!r1&&!r2) return true;
        if(r1&&r2){
            return r1->val==r2->val&&isSymmetric(r1->left,r2->right)&&isSymmetric(r1->right,r2->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root,root);

    }
};
// @lc code=end