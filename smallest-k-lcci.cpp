//
// @lc app=leetcode.cn id=214761599 lang=cpp
//
// [214761599] smallest-k-lcci [最小K个数]
//
class Solution {
public:
    void qs(vector<int>& arr,int l,int r,int k){
        if(l>=r) return;
        int i=l-1;
        int j=r+1;
        int x=arr[l+r>>1];
        while(i<j){
            do i++; while(arr[i]<x);
            do j--; while(arr[j]>x);
            if(i<j)
            swap(arr[i],arr[j]);
        }
        if(k<=j) return qs(arr,l,j,k);
        return qs(arr,j+1,r,k);
    }
    vector<int> smallestK(vector<int>& arr, int k) {
        if(k==0||arr.empty())return{};
        qs(arr,0,arr.size()-1,k-1);
        while(arr.size()>k) arr.pop_back();
        return arr;
    }
};
// @lc code=end