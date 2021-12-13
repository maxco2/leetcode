//
// @lc app=leetcode.cn id=169230230 lang=cpp
//
// [169230230] remove-duplicates-from-sorted-array [删除有序数组中的重复项]
//
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int j=0;
        for(int i=0;i<nums.size();++i){
            if(nums[j]!=nums[i]){
                nums[++j]=nums[i];
            }
        }
        return j+1;
    }
};
// @lc code=end