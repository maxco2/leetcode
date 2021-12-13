//
// @lc app=leetcode.cn id=199994196 lang=cpp
//
// [199994196] search-in-rotated-sorted-array [搜索旋转排序数组]
//
class Solution {
public:
    int target;
    int lv,rv;
    bool check(vector<int>& nums,int mid){
        if(target>lv){
            //target in left half
            if(nums[mid]>=lv){
                return nums[mid]>=target;
            }else{
                return true;
            }
        }else{
            if(nums[mid]>rv){
                return false;
            }else{
                return nums[mid]>=target;
            }
        }
    }
    int search(vector<int>& nums, int _target) {
        target=_target;
        int n=nums.size(),l=0,r=n-1,ans=l;
        lv=nums[l],rv=nums[r];
        if(nums[l]==target) return l;
        if(nums[r]==target) return r;
        while(l<=r){
            int mid=l+r>>1;
            //printf("mid:%d\n",mid);
            if(nums[mid]==target) return mid;
            if(check(nums,mid)) ans=mid,r=mid-1;
            else l=mid+1;
        }
    
        return -1;
    }
};
// @lc code=end