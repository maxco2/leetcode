//
// @lc app=leetcode.cn id=177521583 lang=cpp
//
// [177521583] binary-tree-zigzag-level-order-traversal [二叉树的锯齿形层序遍历]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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
                if(cur_depth%2==0){
                    reverse(c.begin(),c.end());
                }
                ret.push_back(c);
                c.clear();
                c.push_back(t.first->val);
                cur_depth=t.second;
            }
            {
                if(t.first->left){
                    q.push({t.first->left,t.second+1});
                }
                if(t.first->right){
                    q.push({t.first->right,t.second+1});
                }
            }
            q.pop();
        }
        if(!c.empty()){
            if(cur_depth%2==0){
                    reverse(c.begin(),c.end());
            }
            ret.push_back(c);
        } 
        return ret;
    }
};
// @lc code=end