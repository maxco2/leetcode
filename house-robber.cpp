//
// @lc app=leetcode.cn id=168789707 lang=cpp
//
// [168789707] house-robber [打家劫舍]
//
class Solution {
public:
   //dp[1..n]=max(dp[1..n-1],dp[1..n-2]+c[n])
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        auto sz=nums.size();
        int l1=nums[0];
        if(sz==1) return l1;
        int l2=max(l1,nums[1]);
        if(sz==2) return l2;
        int cur=0;
        for(int i=2;i<sz;++i)
        {
            cur=max(l2,l1+nums[i]);
            l1=l2;
            l2=cur;
        }    
        return cur;
    }
};
// @lc code=end