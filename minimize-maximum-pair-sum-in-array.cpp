//
// @lc app=leetcode.cn id=197727348 lang=cpp
//
// [197727348] minimize-maximum-pair-sum-in-array [数组中最大数对和的最小值]
//
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int res=0;
        for(int i=0,j=n-1;i<j;i++,j--){
            res=max(res,nums[i]+nums[j]);
        }
        return res;
    }
};
// @lc code=end