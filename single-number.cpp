//
// @lc app=leetcode.cn id=168789858 lang=cpp
//
// [168789858] single-number [只出现一次的数字]
//
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret=0;
        for(auto n:nums) ret^=n;
        return ret;
    }
};
// @lc code=end