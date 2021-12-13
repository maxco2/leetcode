//
// @lc app=leetcode.cn id=170937026 lang=cpp
//
// [170937026] search-in-rotated-sorted-array-ii [搜索旋转排序数组 II]
//
class Solution {
public:
    int last;
    int first;
    bool check(vector<int>& nums,int mid,int target){
        bool right=false;
        if(nums[mid]==last){//first!=last
            return true;
        }
        if(nums[mid]==first){//first!=last
            return false;
        }
        if(nums[mid]<last){
            //right half
            if(target>last){
                return true;
            }
            if(nums[mid]<target){
                return false;
            }else{
                return true;
            }
        }else{
            if(target<first){
                return false;
            }
            if(nums[mid]<target){
                return false;
            }else{
                return true;
            }
            //left half
        }
    }
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int ans=l;
        last=nums[r];
        first=nums[l];
        if(first==target) return true;
        if(last==target) return true;
        if(first==last){
                for(;l<=r;++l){
                    if(nums[l]==target) return true;
                }
                return false;
        }
        while(l<=r){
            int mid=l+r>>1;
            if(nums[mid]==target) return true;
            if(check(nums,mid,target)) ans=mid,r=mid-1;
            else l=mid+1;
        }
        if(nums[ans]==target) return true;
        return false;
    }
};
// @lc code=end