//
// @lc app=leetcode.cn id=194031028 lang=cpp
//
// [194031028] house-robber-iii [打家劫舍 III]
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
    map<pair<TreeNode*,bool>,int> mem;
    int dfs(TreeNode* t,bool robp){
        if(!t) return 0;
        auto key=pair<TreeNode*,bool>(t,robp);
        if(mem.count(key)) return mem[key];
        int x1=dfs(t->left,false);//not rob cur
        int x2=dfs(t->right,false);//not rob cur
        if(robp){
            int res=x1+x2;
            mem.insert({{t,robp},res});
            return res;
        }else{
            int y1=dfs(t->left,true);
            int y2=dfs(t->right,true);
            int res=max(y1+y2+t->val,x1+x2);
            mem.insert({{t,robp},res});
            return res;
        }
    }
    int rob(TreeNode* root) {
        return dfs(root,false);
    }
};
// @lc code=end