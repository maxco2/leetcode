//
// @lc app=leetcode.cn id=186688558 lang=cpp
//
// [186688558] peak-index-in-a-mountain-array [山脉数组的峰顶索引]
//
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0;
        int r=arr.size()-1;
        int ans=1;
        while(l<=r){
            int mid=l+r>>1;
            if(mid==0) {ans=mid,l=mid+1;continue;}
            if(arr[mid]>arr[mid-1]) ans=mid,l=mid+1;
            else r=mid-1;
        }
        return ans;
    }
};
// @lc code=end