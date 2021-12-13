//
// @lc app=leetcode.cn id=216376998 lang=cpp
//
// [216376998] house-robber-ii [打家劫舍 II]
//
class Solution {
public:
static const int N=120;
    int dp[N][2];
//dp[i][0]=max(dp[i-2][0]+nums[i],dp[i-1][0]) //rob first
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        memset(dp,0,sizeof(dp));
        dp[0][0]=nums[0];
        dp[0][1]=0;
        dp[1][0]=nums[0];
        dp[1][1]=nums[1];
        int n=nums.size();
        for(int i=2;i<n-1;++i){
            dp[i][0]=dp[i-2][0]+nums[i];dp[i][1]=dp[i-2][1]+nums[i];
            dp[i][0]=max(dp[i][0],dp[i-1][0]);
            dp[i][1]=max(dp[i][1],dp[i-1][1]);
            //printf("dp[%d][0]=%d,dp[%d][1]=%d\n",i,dp[i][0],i,dp[i][1]);
        }
        dp[n-1][0]=dp[n-2][0];
        dp[n-1][1]=max(dp[n-3][1]+nums[n-1],dp[n-2][1]);
        return max(dp[n-1][0],dp[n-1][1]);
    }
};
// @lc code=end