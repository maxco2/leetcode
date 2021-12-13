//
// @lc app=leetcode.cn id=215796018 lang=cpp
//
// [215796018] binary-search [二分查找]
//
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid=l+r>>1;
            if(nums[mid]==target) return mid;
            if(nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
        return -1;
    }
};
// @lc code=end