//
// @lc app=leetcode.cn id=179828915 lang=cpp
//
// [179828915] zui-xiao-de-kge-shu-lcof [最小的k个数]
//
class Solution {
public:
    void quick_select(vector<int>& arr,int l,int r,int k){
        if(l>=r) return;
        int x=arr[l+r>>1];
        int i=l-1;
        int j=r+1;
        while(i<j){
            do i++; while(arr[i]<x);
            do j--; while(arr[j]>x);
            if(i<j)
            swap(arr[i],arr[j]);
        }
        if(k<=j) return quick_select(arr,l,j,k);
        return quick_select(arr,j+1,r,k);
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quick_select(arr,0,arr.size()-1,k-1);
        arr.resize(k);
        return arr;
    }
};
// @lc code=end