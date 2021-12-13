//
// @lc app=leetcode.cn id=180057080 lang=cpp
//
// [180057080] er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof [二叉树中和为某一值的路径]
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
    int target;
    vector<vector<int>> ret;
    vector<int> path;
    void dfs(TreeNode* t,int curv){
        if(!t) return;
        if(t->left||t->right){
            if(t->left){
                path.push_back(t->val);
                dfs(t->left,curv+t->val);
                path.pop_back();
            }
            if(t->right){
                path.push_back(t->val);
                dfs(t->right,curv+t->val);
                path.pop_back();
            }
        }else{
            if(t->val+curv==target){
                path.push_back(t->val);
                ret.push_back(path);
                path.pop_back();
            }
        }

    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        this->target=target;
        ret.clear();
        path.clear();
        dfs(root,0);
        return ret;
    }
};
// @lc code=end