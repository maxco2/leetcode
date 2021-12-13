//
// @lc app=leetcode.cn id=201500977 lang=cpp
//
// [201500977] paint-house [粉刷房子]
//
class Solution {
public:
    int dp[110][3];
    int minCost(vector<vector<int>>& costs) {
        memset(dp,0x3f,sizeof dp);
        dp[0][0]=costs[0][0];
        dp[0][1]=costs[0][1];
        dp[0][2]=costs[0][2];
        int n=costs.size();
        for(int i=1;i<costs.size();++i){
            for(int j=0;j<3;++j){
                for(int k=0;k<3;++k){
                    if(k!=j){
                        dp[i][j]=min(dp[i-1][k]+costs[i][j],dp[i][j]);
                    }
                }
                //printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
            }
        }
        return min({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
    }
};
// @lc code=end