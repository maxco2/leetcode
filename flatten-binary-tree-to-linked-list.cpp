//
// @lc app=leetcode.cn id=195989381 lang=cpp
//
// [195989381] flatten-binary-tree-to-linked-list [二叉树展开为链表]
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
    TreeNode* prev;
    void dfs(TreeNode* t){
        if(!t) return ;
        auto tmpl=t->left;
        auto tmpr=t->right;
        if(!prev){
            prev=t;
            t->left=nullptr;
        }
        else{
            prev->right=t;
            t->left=nullptr;
            t->right=nullptr;
            //cout<<"prev"<<prev->val<<endl;
        //cout<<"t->val"<<t->val<<endl;
            prev=t;        
        }
        
        dfs(tmpl);
        dfs(tmpr);
    }
    void flatten(TreeNode* root) {
        prev=nullptr;
        dfs(root);
        //cout<<"?"<<endl;
    }
};
// @lc code=end