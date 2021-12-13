//
// @lc app=leetcode.cn id=180519279 lang=cpp
//
// [180519279] shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof [数组中数字出现的次数 II]
//
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        auto ones=0,twos=0;
        for(auto num:nums){
            ones = ones ^ num & ~twos;
            twos = twos ^ num & ~ones;
        }
        return ones;
    }
};
// @lc code=end