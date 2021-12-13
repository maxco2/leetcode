//
// @lc app=leetcode.cn id=189109301 lang=cpp
//
// [189109301] er-jin-zhi-zhong-1de-ge-shu-lcof [二进制中1的个数]
//
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret=0;
        while(n){
            if(n&1) ret+=1;
            n>>=1;
        }
        return ret;
    }
};
// @lc code=end