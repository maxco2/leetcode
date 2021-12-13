//
// @lc app=leetcode.cn id=171048307 lang=cpp
//
// [171048307] find-minimum-in-rotated-sorted-array-ii [寻找旋转排序数组中的最小值 II]
//
class Solution {
public:
    int findMin(vector<int>& nums) {
        int res=nums[0];
        for(int i=1;i<nums.size();++i){
            res=min(res,nums[i]);
        }
        return res;
    }
};
// @lc code=end