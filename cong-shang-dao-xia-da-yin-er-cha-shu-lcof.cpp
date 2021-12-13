//
// @lc app=leetcode.cn id=179616412 lang=cpp
//
// [179616412] cong-shang-dao-xia-da-yin-er-cha-shu-lcof [从上到下打印二叉树]
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
    vector<int> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<int> ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            ret.push_back(cur->val);
            if(cur->left){
                q.push(cur->left);
            }
            if(cur->right){
                q.push(cur->right);
            }
        }
        return ret;


    }
};
// @lc code=end