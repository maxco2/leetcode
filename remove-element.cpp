//
// @lc app=leetcode.cn id=169285377 lang=cpp
//
// [169285377] remove-element [移除元素]
//
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j=-1;
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=val){
                nums[++j]=nums[i];
            }
        }
        return j+1;
    }
};
// @lc code=end