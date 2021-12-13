//
// @lc app=leetcode.cn id=193940040 lang=cpp
//
// [193940040] climbing-stairs [爬楼梯]
//
class Solution {
public:
    int climbStairs(int n) {
        //dp[3]=dp[2]+dp[1]
        int l1=1;
        if(n==1) return l1;
        int l2=2;
        if(n==2) return l2;
        int cur=0;
        for(int i=3;i<=n;++i)
        {
            cur=l2+l1;
            l1=l2;
            l2=cur;
        }
        return cur;
    }
};
// @lc code=end