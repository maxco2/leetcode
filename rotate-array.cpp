//
// @lc app=leetcode.cn id=198390934 lang=cpp
//
// [198390934] rotate-array [轮转数组]
//
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
// @lc code=end