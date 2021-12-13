//
// @lc app=leetcode.cn id=198756537 lang=cpp
//
// [198756537] path-sum-iii [路径总和 III]
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
    unordered_map<int,int> mem;
    int dfs(TreeNode* t,int tar,int cur){
        if(!t) return 0;
        int res=0;
        cur+=t->val;
        if(mem.count(cur-tar)) res+=mem[cur-tar];
        mem[cur]++;
        res+=dfs(t->left,tar,cur);
        res+=dfs(t->right,tar,cur);
        mem[cur]--;
        return res;
    }
    int pathSum(TreeNode* root, int targetSum) {
        mem[0]++;
        return dfs(root,targetSum,0);
    }
};
// @lc code=end