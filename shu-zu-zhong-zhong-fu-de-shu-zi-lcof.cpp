//
// @lc app=leetcode.cn id=169657936 lang=cpp
//
// [169657936] shu-zu-zhong-zhong-fu-de-shu-zi-lcof [数组中重复的数字]
//
int dp[100001];
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        memset(dp,0,sizeof(dp));
        for(auto n:nums){
            if(dp[n]!=0){
                return n;
            }
            dp[n]+=1;
        }
        return 0;
    }
};
// @lc code=end