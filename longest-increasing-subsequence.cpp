//
// @lc app=leetcode.cn id=181570979 lang=cpp
//
// [181570979] longest-increasing-subsequence [最长递增子序列]
//
class Solution {
public:
    int dp[2505];
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,0,sizeof(dp));
        dp[0]=-1e5;
        int idx=0;
        int ret=1;
        dp[1]=nums[0];
        for(auto n:nums){
            int l=0;
            int r=ret;
            int ans=ret;
            while(l<=r){
                int mid=l+r>>1;
                if(dp[mid]<n) ans=mid,l=mid+1;
                else r=mid-1;
            }
            dp[ans+1]=n;
            ret=max(ret,ans+1);
            idx+=1;
        }
        return ret;
    }
};
// @lc code=end