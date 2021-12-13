//
// @lc app=leetcode.cn id=170967950 lang=cpp
//
// [170967950] minimum-size-subarray-sum [长度最小的子数组]
//
class Solution {
public:
    //S[j]-S[k]>=target min(k-j)
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int count=0;
        int res=nums.size();
        for(auto& n:nums){
            if(n>=target) return 1;
            count+=1;
            sum+=n;
            if(sum>=target) res=min(res,count);
            n=sum;
        }
        if(sum<target) return 0;
        if(sum==target) return nums.size();
        int i=0;
        int j=0;
        while(i<=j&&j<nums.size()){
            if(nums[j]-nums[i]<target){
                j++;
            }else{
                res=min(j-i,res);
                i++;
            }
        }
        return res;
    }
};
// @lc code=end