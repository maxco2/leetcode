//
// @lc app=leetcode.cn id=192793133 lang=cpp
//
// [192793133] er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof [二叉搜索树的后序遍历序列]
//
class Solution {
public:
    int st[1010];
    bool verifyPostorder(vector<int>& postorder) {
        int top=0;
        auto prev=INT_MAX;
        for(auto it=postorder.rbegin();it!=postorder.rend();++it){
            if(*it>prev) return false;
            while(top>0&&(*it)<st[top-1]){
                prev=st[--top];
            }
            st[top++]=*it;
        }
        return true;
    }
};
// @lc code=end