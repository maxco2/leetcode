//
// @lc app=leetcode.cn id=194411446 lang=cpp
//
// [194411446] concatenation-of-array [数组串联]
//
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ret=nums;
        ret.insert(ret.end(),nums.begin(),nums.end());
        return ret;

    }
};
// @lc code=end