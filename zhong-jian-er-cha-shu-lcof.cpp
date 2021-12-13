//
// @lc app=leetcode.cn id=178831335 lang=cpp
//
// [178831335] zhong-jian-er-cha-shu-lcof [重建二叉树]
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
    TreeNode* buildTree(vector<int>& preorder,int st,vector<int>& inorder,int st1,int ed1) {
        if(st1>ed1) return nullptr;
        TreeNode* t=new TreeNode(preorder[st]);
        if(st1==ed1){
            return t;
        }
        for(int i=st1;i<=ed1;++i){
            if(inorder[i]==preorder[st]){
                t->left=buildTree(preorder,st+1,inorder,st1,i-1);
                t->right=buildTree(preorder,st+1+(i-st1),inorder,i+1,ed1);
                break;
            }
        }
        return t;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return nullptr;
        return buildTree(preorder,0,inorder,0,inorder.size()-1);

    }
};
// @lc code=end