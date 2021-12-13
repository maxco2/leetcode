//
// @lc app=leetcode.cn id=200607379 lang=cpp
//
// [200607379] all-nodes-distance-k-in-binary-tree [二叉树中所有距离为 K 的结点]
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
    int k;
    vector<int> ret;
    unordered_map<TreeNode*,TreeNode*> fa;
    void dfs(TreeNode* t){
        if(!t) return;    
        if(t->left)
        fa[t->left]=t,dfs(t->left);
        if(t->right)
        fa[t->right]=t,dfs(t->right);
    }

    void bfs(TreeNode* tt){
        queue<TreeNode*> q;
        q.push(tt);
        unordered_map<TreeNode*,int> mem;
        mem[tt]=0;
        while(!q.empty()){
            auto t=q.front();q.pop();
            auto d=mem[t];
            if(d==k){
                ret.push_back(t->val);
                continue;
            }
            if(t->left&&!mem.count(t->left)){
                q.push(t->left);
                mem[t->left]=d+1;
            }
            if(t->right&&!mem.count(t->right)){
                q.push(t->right);
                mem[t->right]=d+1;
            }
            auto p=fa[t];
            if(p&&!mem.count(p)){
                q.push(p);
                mem[p]=d+1;
            }

        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0) return {target->val};
        ret.clear();
        this->k=k;
        fa[root]=NULL;
        dfs(root);
        bfs(target);
        return ret;
    }
};
// @lc code=end