//
// @lc app=leetcode.cn id=186972228 lang=cpp
//
// [186972228] product-of-array-except-self [除自身以外数组的乘积]
//
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size(),1);
        int res=1;
        int n=nums.size();
        for(int i=n-1;i-1>=0;i--)
        {
            res*=nums[i];
            ret[i-1]=res;
        }
        res=1;
        for(int i=0;i+1<nums.size();++i){
            res*=nums[i];
            ret[i+1]*=res;
        }
        return ret;
    }
};
// @lc code=end