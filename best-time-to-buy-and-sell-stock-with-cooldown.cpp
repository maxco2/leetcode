//
// @lc app=leetcode.cn id=186885836 lang=cpp
//
// [186885836] best-time-to-buy-and-sell-stock-with-cooldown [最佳买卖股票时机含冷冻期]
//
class Solution {
public:
    // dp[j] 在第j天卖出股票可获得最大利润
    // dp[j]=max(p[j-1]-p[i-1]+max(dp[k]))  2<=i<j   1<=k<=i-2
    int maxProfit(vector<int>& prices) {
        int res=0;
        vector<int> dp(prices.size()+1,0);
        vector<int> dpk(prices.size()+1,0);
        for(int i=1;i<=prices.size();++i){
            dp[i]=max(dp[i],prices[i-1]-prices[0]);
            res=max(dp[i],res);
            for(int j=2;j<i;++j){
                dp[i]=max(dp[i],prices[i-1]-prices[j-1]+dpk[j-2]);
                res=max(dp[i],res);
            }
            dpk[i]=res;
        }
        return res;
    }
};
// @lc code=end