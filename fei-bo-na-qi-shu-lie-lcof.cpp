//
// @lc app=leetcode.cn id=203738463 lang=cpp
//
// [203738463] fei-bo-na-qi-shu-lie-lcof [斐波那契数列]
//
class Solution {
public:
static const int MOD=1e9+7;
    int fib(int n) {
        if(n<=1) return n;
        int f0=0;
        int f1=1;
        for(int i=2;i<=n;++i){
            auto tmp=(f0+f1)%MOD;
            f0=f1%MOD;
            f1=tmp;
        }
        return f1;
    }
};
// @lc code=end