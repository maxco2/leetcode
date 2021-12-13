//
// @lc app=leetcode.cn id=196289183 lang=cpp
//
// [196289183] zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof [在排序数组中查找数字 I]
//
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return upper_bound(nums.begin(),nums.end(),target)-lower_bound(nums.begin(),nums.end(),target);
    }
};
// @lc code=end