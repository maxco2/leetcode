//
// @lc app=leetcode.cn id=196216829 lang=cpp
//
// [196216829] jump-game-ii [跳跃游戏 II]
//
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        vector<int> dp(nums.size(),0x3f3f3f3f);
        dp[0]=0;
        for(int i=1;i<nums.size();++i){
            for(int j=0;j<i;++j){
                if(nums[j]+j>=i){
                    dp[i]=min(dp[j]+1,dp[i]);
                }
            }
        }
        return dp[nums.size()-1];
    }
};
// @lc code=end