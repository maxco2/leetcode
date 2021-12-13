//
// @lc app=leetcode.cn id=193787472 lang=cpp
//
// [193787472] yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof [圆圈中最后剩下的数字]
//
class Solution {
public:
    int f(int n,int m){
        if(n==1) return 0;
        int x=f(n-1,m);
        return (m+x)%n;
    }
    int lastRemaining(int n, int m) {
        return f(n,m);
    }
};
// @lc code=end