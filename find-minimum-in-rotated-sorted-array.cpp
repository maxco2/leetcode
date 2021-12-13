//
// @lc app=leetcode.cn id=171047503 lang=cpp
//
// [171047503] find-minimum-in-rotated-sorted-array [寻找旋转排序数组中的最小值]
//
class Solution {
public:
    // 1245670
    // 4567012
    int first;
    int last;
    bool check(vector<int>& nums,int mid){
        if(mid==nums.size()-1){
            return true;
        }
        if(mid==0){
            return false;
        }
        if(nums[mid]>last){
            //left half
            return false;
        }else{
            return true;
        }
    }
    int findMin(vector<int>& nums) {
        if(nums.size()==2) return min(nums[0],nums[1]);
        first=nums[0];
        int l=0;
        int r=nums.size()-1;
        last=nums[r];
        if(first<=last) return first;
        if(first>last&&last<nums[nums.size()-2]) return last;
        int ans=l;
        while(l<=r){
            int mid=l+r>>1;
            if(check(nums,mid)) ans=mid,r=mid-1;
            else l=mid+1;
        }
        return nums[ans];
    }
};
// @lc code=end