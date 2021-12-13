//
// @lc app=leetcode.cn id=195180158 lang=cpp
//
// [195180158] move-zeroes [移动零]
//
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0;
        int n=nums.size();
        int right=0;
        while(right<n){
            if(nums[right]){
                swap(nums[left],nums[right]);
                left++;
            }
            right++;
        }
    }
};
// @lc code=end