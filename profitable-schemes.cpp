//
// @lc app=leetcode.cn id=186014097 lang=cpp
//
// [186014097] profitable-schemes [盈利计划]
//
class Solution {
public:
    using ull=unsigned long long;
    const int mod = (int)(1e9)+7;
    ull dp[105][10005];//group,profit
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,0,sizeof(dp));
        int sum=0;
        dp[0][0]=1;
        for(int i=0;i<group.size();++i){
            //dp[group[i]][profit[i]]+=1;
            sum+=profit[i];
        }
        for(int i=0;i<group.size();++i){
            for(int j=n;j>=group[i];--j){
                for(int k=sum;k>=profit[i];--k){
                    dp[j][k]=(dp[j-group[i]][k-profit[i]]+dp[j][k])%mod;
                    //printf("dp[%d][%d]=%d\n",j,k,dp[j][k]);
                }
            }
        }
        int ret=0;
        if(minProfit==0) ret=1;
        for(int i=1;i<=n;++i)
        for(int j=minProfit;j<=sum;++j){
            ret+=dp[i][j];
            ret%=mod;
        }
        return ret;
    }
};
// @lc code=end