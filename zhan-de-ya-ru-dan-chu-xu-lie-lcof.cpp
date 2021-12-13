//
// @lc app=leetcode.cn id=211571093 lang=cpp
//
// [211571093] zhan-de-ya-ru-dan-chu-xu-lie-lcof [栈的压入、弹出序列]
//
class Solution {
public:
    int st[1010];
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,top=0;
        for(auto n:pushed){
            st[top++]=n; while(top>0&&st[top-1]==popped[i]) top--,i++;
        }
        return top==0;
    }
};
// @lc code=end