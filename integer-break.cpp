//
// @lc app=leetcode.cn id=171893656 lang=cpp
//
// [171893656] integer-break [整数拆分]
//
unsigned int dp[60];
class Solution {
public:
//a+b+c>=3 three root of(abc)
    int integerBreak(int n) {
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