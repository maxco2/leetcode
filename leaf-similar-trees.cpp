//
// @lc app=leetcode.cn id=176263518 lang=cpp
//
// [176263518] leaf-similar-trees [叶子相似的树]
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
    vector<int> l1;
    vector<int> l2;
    void calc(TreeNode* root,vector<int>& l){
        if(root){
            if(!root->left&&!root->right) l.push_back(root->val);
            if(root->left) calc(root->left,l);
            if(root->right) calc(root->right,l);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        l1.clear();
        l2.clear();
        calc(root1,l1);
        calc(root2,l2);
        return l1==l2;
    }
};
// @lc code=end