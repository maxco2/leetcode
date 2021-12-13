//
// @lc app=leetcode.cn id=191094638 lang=cpp
//
// [191094638] maximum-product-subarray [乘积最大子数组]
//
class Solution {
public:
    // dp[j] = max(dp[j-1]*n[j],n[j])
    int maxProduct(vector<int>& nums) {
        vector<int> dp(nums.size()+1,1),dp1(nums.size()+1,1);
        int res=INT_MIN;
        for(int i=0;i<nums.size();++i){
            dp[i+1]=max({dp[i]*nums[i],nums[i],dp1[i]*nums[i]});
            dp1[i+1]=min({dp[i]*nums[i],dp1[i]*nums[i],nums[i]});
            res=max({res,dp[i+1],dp1[i+1]});
        }
        return res;
    }
};
// @lc code=end