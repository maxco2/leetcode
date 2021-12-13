//
// @lc app=leetcode.cn id=177454616 lang=cpp
//
// [177454616] que-shi-de-shu-zi-lcof [0～n-1中缺失的数字]
//
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        int ans=r;
        while(l<=r){
            int mid=l+r>>1;
            if(nums[mid]!=mid) ans=mid,r=mid-1;
            else l=mid+1;
        }
        return ans==nums[ans]?nums.size():ans;
    }
};
// @lc code=end