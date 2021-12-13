//
// @lc app=leetcode.cn id=222266498 lang=cpp
//
// [222266498] coin-change-2 [零钱兑换 II]
//
class Solution {
public:
    int dp[5010];
    int change(int amount, vector<int>& coins) {
        memset(dp,0,sizeof dp);
        dp[0]=1;
        for(auto v:coins){
            for(int j=v;j<=amount;++j)
            dp[j]=dp[j-v]+dp[j];
        }
        return dp[amount];
    }
};
// @lc code=end