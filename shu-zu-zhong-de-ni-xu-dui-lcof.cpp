//
// @lc app=leetcode.cn id=175582765 lang=cpp
//
// [175582765] shu-zu-zhong-de-ni-xu-dui-lcof [数组中的逆序对]
//
class Solution {
public:
    int tmp[50005];
    int merge_sort(vector<int>& nums,int l,int r){
        if(l>=r) return 0;
        int mid=l+r>>1;
        int f1=merge_sort(nums,l,mid);
        int f2=merge_sort(nums,mid+1,r);
        int f3=f1+f2;
        int i=l,j=mid+1,k=0;
        while(i<=mid&&j<=r){
            if(nums[i]<=nums[j]){
                tmp[k++]=nums[i++];
            }else tmp[k++]=nums[j++],f3+=(mid-i+1);
        }
        while(i<=mid) tmp[k++]=nums[i++];
        while(j<=r) tmp[k++]=nums[j++];
        for(i=l,k=0;k<r-l+1;) nums[i++]=tmp[k++];
        return f3;
    }
    int reversePairs(vector<int>& nums) {
        return merge_sort(nums,0,nums.size()-1);
    }
};
// @lc code=end