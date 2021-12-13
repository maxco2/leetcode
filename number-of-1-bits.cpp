//
// @lc app=leetcode.cn id=172000577 lang=cpp
//
// [172000577] number-of-1-bits [位1的个数]
//
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum=0;
        while(n){
            sum+=n&1;
            n=n>>1;
        }
        return sum;
    }
};
// @lc code=end