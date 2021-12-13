//
// @lc app=leetcode.cn id=168789801 lang=cpp
//
// [168789801] reverse-bits [颠倒二进制位]
//
#include <bits/stdc++.h>
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t r=0;
        for(int i=0;i<32;++i)
            r=(r<<1)+(n>>i&1);
        return r;
    }
};
// @lc code=end