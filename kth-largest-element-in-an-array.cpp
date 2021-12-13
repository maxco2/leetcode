//
// @lc app=leetcode.cn id=183453101 lang=cpp
//
// [183453101] kth-largest-element-in-an-array [数组中的第K个最大元素]
//
class Solution {
public:
    int qs(vector<int>& nums,int l,int r,int k){
        //cout<<"l"<<l<<" r"<<r<<endl;
        if(l==r) return nums[r];
        int mid=nums[l+r>>1];
        int i=l-1;
        int j=r+1;
        //cout<<"?"<<endl;
        //cout<<"i"<<i<<" j"<<j<<endl;
        while(i<j){
            do i++; while(nums[i]>mid);
            do j--; while(nums[j]<mid);
            if(i<j)
            swap(nums[i],nums[j]);
        }
        //cout<<"fuck"<<endl;
        if(j>=k) return qs(nums,l,j,k);
        return qs(nums,j+1,r,k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size()-1;
        return qs(nums,0,n,k-1);
    }
};
// @lc code=end