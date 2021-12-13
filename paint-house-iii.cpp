//
// @lc app=leetcode.cn id=177778939 lang=cpp
//
// [177778939] paint-house-iii [粉刷房子 III]
//
class Solution {
public:
    //dp[i][j][k] 第i个房子,涂第j个颜色,形成k+1个街区的最小花费
    //dp[i][j][k]=min(dp[i-1][j][k]+cost[i],dp[i-1][!j][k-1]+cost[i]) not painting
    // paninting = dp[i-1][j][k],dp[i-1][!j][k-1];
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(houses.size(),vector<vector<int>>(n,vector<int>(target,(int)1e7)));
        if(houses[0]==0)
        for(int i=0;i<n;++i)
            dp[0][i][0]=cost[0][i];
        else
        dp[0][houses[0]-1][0]=0;
        for(int i=1;i<houses.size();++i){
            if(houses[i]==0){
                for(int j=0;j<n;j++){
                //printf("i:%d,j:%d\n",i,j);
                    dp[i][j][0] = dp[i-1][j][0]+cost[i][j];
                    //dp[i][j][1]=dp[i-1][j][1]+cost[i][j];
                    for(int k=1;k<target;++k){
                        dp[i][j][k]=dp[i-1][j][k]+cost[i][j];
                        for(int jj=0;jj<n;jj++){
                            if(jj!=j)
                            dp[i][j][k]=min(dp[i-1][jj][k-1]+cost[i][j],dp[i][j][k]);
                        }
                    }
                }
            }else{
                //printf("already painted i:%d,j:%d\n",i,houses[i]-1);
                int j=houses[i]-1;
                dp[i][j][0]=dp[i-1][j][0];
                //dp[i][houses[i]][1]
                for(int k=1;k<target;++k){
                        dp[i][j][k]=dp[i-1][j][k];
                        for(int jj=0;jj<n;jj++){
                            if(jj!=j)
                            dp[i][j][k]=min(dp[i-1][jj][k-1],dp[i][j][k]);
                        }
                }
            }
        }
        int ret=dp[houses.size()-1][0][target-1];
        for(int j=1;j<n;++j) ret=min(ret,dp[houses.size()-1][j][target-1]);
        return ret>=((int)1e7)?-1:ret;
    }
};
// @lc code=end