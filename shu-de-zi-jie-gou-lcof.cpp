//
// @lc app=leetcode.cn id=172008197 lang=cpp
//
// [172008197] shu-de-zi-jie-gou-lcof [树的子结构]
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
    TreeNode* b;
    bool dfs(TreeNode* A){
        if(!A) return false;
        if(A->val==b->val){
            if(isSubStructure2(A,b)){
                return true;
            }
        }
        bool l=dfs(A->left);
        bool r=dfs(A->right);
        return l||r;
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!B) return false;
        b=B;
        return dfs(A);
    }
    bool isSubStructure2(TreeNode* A, TreeNode* B) {
        if(!A&&!B) return true;
        if(A==NULL&&B) return false;
        if(A&&B==NULL) return true;
        if(A->val==B->val){
            bool l=isSubStructure2(A->left,B->left);
            bool r=isSubStructure2(A->right,B->right);
            if(l&&r) return true;
        }
        return false;
    }
};
// @lc code=end