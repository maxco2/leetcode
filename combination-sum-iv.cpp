//
// @lc app=leetcode.cn id=171871535 lang=cpp
//
// [171871535] combination-sum-iv [组合总和 Ⅳ]
//
unsigned long long dp[1005];
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(auto i=0;i<=target;++i){
            for(auto n:nums){
                if(i-n>=0)
                dp[i]+=dp[i-n];
            }
        }
        return dp[target];
    }
};
// @lc code=end