//
// @lc app=leetcode.cn id=170956450 lang=cpp
//
// [170956450] find-peak-element [寻找峰值]
//
class Solution {
public:

    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int l=0;
        int r=nums.size()-1;
        int ans=l;
        while(l<=r){
            int mid=l+r>>1;
            int midr=mid+1;
            int midl=mid-1;
            if(midl>=0&&midr<nums.size()){
                if(nums[mid]>nums[midl]&&nums[mid]>nums[midr]){
                    return mid;
                }else if(nums[mid]<nums[midl]&&nums[mid]>nums[midr]){
                    ans=mid;r=mid-1;
                }else if(nums[mid]<nums[midr]&&nums[mid]>nums[midl]){
                    l=mid+1;
                }else if(nums[mid]<nums[midl]&&nums[mid]<nums[midr]){
                    ans=mid;r=mid-1;
                }
            }else if(midl>=0){
                if(nums[mid]>nums[midl]){
                    return mid;
                }else{
                    ans=mid,r=mid-1;
                }
            }else if(midr<nums.size()){
                if(nums[mid]>nums[midr]){
                    return mid;
                }else{
                    l=mid+1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end