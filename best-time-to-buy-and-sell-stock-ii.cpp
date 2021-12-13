//
// @lc app=leetcode.cn id=193933885 lang=cpp
//
// [193933885] best-time-to-buy-and-sell-stock-ii [买卖股票的最佳时机 II]
//
const int N=3e4+10;
class Solution {
public:
    int dp[N][2];
    int maxProfit(vector<int>& prices) {
        memset(dp,0,sizeof(dp));
        dp[0][0]=-prices[0];
        dp[0][1]=0;
        int res=0;
        for(int i=1;i<prices.size();++i){
            dp[i][1]=max(dp[i-1][0]+prices[i],dp[i-1][1]);
            dp[i][0]=max(dp[i-1][1]-prices[i],dp[i-1][0]);
        }
        return max(dp[prices.size()-1][1],dp[prices.size()-1][0]);
        
    }
};
// @lc code=end