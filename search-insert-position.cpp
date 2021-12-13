//
// @lc app=leetcode.cn id=169288528 lang=cpp
//
// [169288528] search-insert-position [搜索插入位置]
//
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int l=0;
        int r=nums.size()-1;
        if(nums[r]<target) return r+1;
        int res=l;
        while(l<=r){
            int mid=l+r>>1;
            if(nums[mid]>=target) res=mid,r=mid-1;
            else l=mid+1;
        }
        return res;

    }
};
// @lc code=end