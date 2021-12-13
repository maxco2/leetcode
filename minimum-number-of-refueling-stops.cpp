//
// @lc app=leetcode.cn id=178180820 lang=cpp
//
// [178180820] minimum-number-of-refueling-stops [最低加油次数]
//
class Solution {
public:
// dp[i][N] 前i个加油站在加油N次可行驶最大里程数
//dp[i][N]=max(dp[i-1][N],dp[i-1][N-1]+stations[i][1] if dp[i-1][N-1]>stations[i][0])
//dp[n][N] check all >target get min N
    long long dp[505];
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(startFuel>=target) return 0;
        int n=stations.size();
        //memset(dp,0,sizeof(dp));
        dp[0]=startFuel;
        for(int i=1;i<n;++i) dp[i]=INT_MIN;
        for(int i=0;i<stations.size();++i){
            for(int j=n;j>=1;--j){
                if(dp[j-1]>=stations[i][0])
                    dp[j]=max(dp[j],dp[j-1]+stations[i][1]);
            }
        }
        for(int i=1;i<=n;++i){
            if(dp[i]>=target){
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end