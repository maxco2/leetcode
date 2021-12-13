//
// @lc app=leetcode.cn id=179619976 lang=cpp
//
// [179619976] cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof [从上到下打印二叉树 III]
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
    vector<vector<int>> ret;
    vector<int> c;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return{};
        ret.clear();
        c.clear();
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        int cd=1;
        bool r=false;
        while(!q.empty()){
            auto tmp=q.front();
            q.pop();
            auto cur=tmp.first;
            auto depth=tmp.second;
            if(cd==depth){
                c.push_back(cur->val);
            }else{
                if(r){
                    reverse(c.begin(),c.end());
                }
                r=!r;
                ret.push_back(c);
                c.clear();
                c.push_back(cur->val);
                cd=depth;
            }
                if(cur->left){
                    q.push({cur->left,depth+1});
                }
                if(cur->right){
                    q.push({cur->right,depth+1});
                }
                
            
        }
        if(r){
            reverse(c.begin(),c.end());
        }
        if(!c.empty())
        {ret.push_back(c);}
        return ret;

    }
};
// @lc code=end