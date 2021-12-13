//
// @lc app=leetcode.cn id=11212651 lang=cpp
//
// [11212651] maximum-subarray [最大子数组和]
//
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0];
        int res=sum;
        for(int i=1;i<nums.size();++i)
        {
            if(sum<=0)
                sum=nums[i];
            else
                sum+=nums[i];
            res=max(sum,res); 
        }
        return res;
    }
};
// @lc code=end