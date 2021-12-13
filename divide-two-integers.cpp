//
// @lc app=leetcode.cn id=195600480 lang=cpp
//
// [195600480] divide-two-integers [两数相除]
//
class Solution {
public:
    int divide(int dd, int d) {
        if(dd==INT_MIN&&d==-1) return INT_MAX;
return (long long)dd/(long long)d;
    }
};
// @lc code=end