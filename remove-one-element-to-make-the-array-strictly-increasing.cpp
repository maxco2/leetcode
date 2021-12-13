//
// @lc app=leetcode.cn id=189990856 lang=cpp
//
// [189990856] remove-one-element-to-make-the-array-strictly-increasing [删除一个元素使数组严格递增]
//
class Solution {
public:
    bool check(vector<int>& nums,int j){
        for(int i=0;i<nums.size()-1;++i){
            if(i!=j&&i+1!=j){
                if(nums[i]>=nums[i+1]){
                    return false;
                }
            }else if(i==j){
                continue;
            }else if(i+1==j){
                if(i+2<nums.size()){
                    if(nums[i]>=nums[i+2]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool canBeIncreasing(vector<int>& nums) {
        for(int i=0;i<nums.size();++i){
            if(check(nums,i)){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end