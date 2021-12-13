//
// @lc app=leetcode.cn id=211527556 lang=cpp
//
// [211527556] find-first-and-last-position-of-element-in-sorted-array [在排序数组中查找元素的第一个和最后一个位置]
//
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto p1=lower_bound(nums.begin(),nums.end(),target);
        auto p2=upper_bound(nums.begin(),nums.end(),target);
        if(p1==nums.end()||*p1!=target){
            return {-1,-1};
        }
        int l=p1-nums.begin();
        int r=p2-nums.begin()-1;
        return {l,r};
    }
};
// @lc code=end