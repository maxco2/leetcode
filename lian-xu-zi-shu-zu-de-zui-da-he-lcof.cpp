//
// @lc app=leetcode.cn id=196586536 lang=cpp
//
// [196586536] lian-xu-zi-shu-zu-de-zui-da-he-lcof [连续子数组的最大和]
//
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int x=0;
        int sum=0;
        int res=-1e9;
        for(auto& n:nums){
            sum+=n;
            res=max(res,sum-x);
            x=min(x,sum);
            n=sum;
        }
        return res;

    }
};
// @lc code=end