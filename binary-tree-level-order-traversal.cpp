//
// @lc app=leetcode.cn id=177517602 lang=cpp
//
// [177517602] binary-tree-level-order-traversal [二叉树的层序遍历]
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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        vector<int> c;
        queue<pair<TreeNode*,int>> q;
        int cur_depth=1;
        q.push({root,1});
        while(!q.empty()){
            auto t=q.front();
            if(t.second==cur_depth){
                c.push_back(t.first->val);
            }else{
                ret.push_back(c);
                c.clear();
                c.push_back(t.first->val);
                cur_depth=t.second;
            }
            if(t.first->left){
                q.push({t.first->left,cur_depth+1});
            }
            if(t.first->right){
                q.push({t.first->right,cur_depth+1});
            }
            q.pop();
        }
        if(!c.empty()) ret.push_back(c);
        return ret;
    }
};
// @lc code=end