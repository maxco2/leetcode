//
// @lc app=leetcode.cn id=190055845 lang=cpp
//
// [190055845] maximum-product-difference-between-two-pairs [两个数对之间的最大乘积差]
//
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        auto n=nums.size();
        return nums[n-1]*nums[n-2]-nums[0]*nums[1];
    }
};
// @lc code=end