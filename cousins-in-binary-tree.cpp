//
// @lc app=leetcode.cn id=178111543 lang=cpp
//
// [178111543] cousins-in-binary-tree [二叉树的堂兄弟节点]
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
    TreeNode* parentx;
    TreeNode* parenty;

    int depth;
   
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;
        parentx=nullptr;
        parenty=nullptr;
        int xd=0;
        int yd=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        depth=1;
        while(!q.empty()){
            auto t=q.front().first;
            auto curd=q.front().second;
            q.pop();
            if(t->left) {
                if(t->left->val==x)
                    parentx=t,xd=curd+1;
                if(t->left->val==y)
                    parenty=t,yd=curd+1;
                q.push({t->left,curd+1});
            }
            if(t->right) {
                if(t->right->val==x)
                    parentx=t,xd=curd+1;
                if(t->right->val==y)
                    parenty=t,yd=curd+1;
                q.push({t->right,curd+1});
            }
            if(parentx&&parenty){
                if(parentx!=parenty){
                    if(xd==yd)
                    return true;
                }
                return false;
            }
        }
        return false;
        
    }
};
// @lc code=end