//
// @lc app=leetcode.cn id=186016005 lang=cpp
//
// [186016005] perfect-squares [完全平方数]
//
class Solution {
public:
    int numSquares(int n) {
        int x=(sqrt(n));
        if(x*x==n) return 1;
        vector<long> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=x;++i){
            for(int j=i*i;j<=n;++j)
            dp[j]=min(dp[j],dp[j-i*i]+1);
        }
        return dp[n];

    }
};
// @lc code=end