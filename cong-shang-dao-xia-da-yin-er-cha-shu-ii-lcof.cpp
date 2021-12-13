//
// @lc app=leetcode.cn id=179617936 lang=cpp
//
// [179617936] cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof [从上到下打印二叉树 II]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ret;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        vector<int> c;
        int cd=1;
        while(!q.empty()){
            auto tmp=q.front();
            q.pop();
            auto cur=tmp.first;
            auto depth=tmp.second;
            if(cd==depth){
                c.push_back(cur->val);
            }else{
                cd=depth;
                ret.push_back(c);
                c.clear();
                c.push_back(cur->val);
            }
            if(cur->left){
                q.push({cur->left,depth+1});
            }
            if(cur->right){
                q.push({cur->right,depth+1});
            }
        }
        if(!c.empty()) ret.push_back(c);
        return ret;

    }
};
// @lc code=end