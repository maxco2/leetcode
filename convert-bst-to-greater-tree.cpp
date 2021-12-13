//
// @lc app=leetcode.cn id=193398033 lang=cpp
//
// [193398033] convert-bst-to-greater-tree [把二叉搜索树转换为累加树]
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
const int N = 1e14+10;
class Solution {
public:
    int cnt;
    vector<int> node;
    vector<int> pre;
    //int pre[N];
    void dfs(TreeNode* t){
        if(!t) return;
        node.push_back(t->val);
        cnt++;
        dfs(t->left);
        dfs(t->right);
    }

    void assign(TreeNode* t){
        if(!t) return;
        int l=1;
        int r=cnt-1;
        int ans=r;
        while(l<=r){
            int mid=l+r>>1;
            if(node[mid]>=t->val) ans=mid,r=mid-1;
            else l=mid+1;
        }
        t->val=pre[cnt-1]-pre[ans-1];
        assign(t->left);
        assign(t->right);
    }

    TreeNode* convertBST(TreeNode* root) {
        if(!root) return root;
        cnt=1;
        node.clear();
        node.push_back(0);
        dfs(root);
        sort(node.begin()+1,node.end());
        pre=vector<int>(cnt,0);
        for(int i=1;i<cnt;++i){
            pre[i]=pre[i-1]+node[i];
        }
        assign(root);
        return root;

    }
}; 
// @lc code=end