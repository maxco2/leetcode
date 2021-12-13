//
// @lc app=leetcode.cn id=178832165 lang=cpp
//
// [178832165] jian-sheng-zi-lcof [剪绳子]
//
class Solution {
public:
unsigned int dp[60];
    int cuttingRope(int n) {
memset(dp,0,sizeof(dp));
        dp[0]=1;
        dp[1]=1;
        for(int i=1;i<n;++i){
            for(int j=i;j<=n;j++){
                dp[j]=max(dp[j],dp[j-i]*i);
            }
        }
        return dp[n];
    }
};
// @lc code=end