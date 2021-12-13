//
// @lc app=leetcode.cn id=168789775 lang=cpp
//
// [168789775] coin-change [零钱兑换]
//
//dp[i][j]=min(dp[i-1][j],dp[i-1][j-c_i]+1,dp[i-1][j-2*c_i]+2,....)
//dp[i][j-c_i]=min(dp[i-1][j-c_i],dp[i-1][j-2*c_i]+1,...)
//dp[i][j]=min(dp[i-1][j],dp[i-1][j-c_i]+1)
int64_t dp[10005];
class Solution {
public:
    int coinChange(vector<int>& coins, int a) {
        if(a==0) return 0;
        for(int i=1;i<10005;++i)
            dp[i]=std::numeric_limits<unsigned int>::max();
        dp[0]=0;
        for(int i=0;i<coins.size();++i)
        {
            for(int j=coins[i];j<=a;j++)
            {
                dp[j]=min(dp[j],dp[j-coins[i]]+1);
            }
        }
        return dp[a];
    }
};
// @lc code=end