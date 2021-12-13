//
// @lc app=leetcode.cn id=177404049 lang=cpp
//
// [177404049] path-sum-ii [路径总和 II]
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
    vector<vector<int>> ret;
    vector<int> c;
    void dfs(TreeNode* t,int remain,vector<int>& c){
        if(t){
            if(remain==t->val&&!t->left&&!t->right){
                c.push_back(t->val);
                ret.push_back(c);
                c.pop_back();
                return;
            }
            remain-=t->val;
            c.push_back(t->val);
            if(t->left){
                dfs(t->left,remain,c);
            }
            if(t->right){
                dfs(t->right,remain,c);
            }
            c.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        ret.clear();
        c.clear();
        dfs(root,targetSum,c);
        return ret;
    }
};
// @lc code=end