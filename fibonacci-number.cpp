//
// @lc app=leetcode.cn id=194276412 lang=cpp
//
// [194276412] fibonacci-number [斐波那契数]
//
class Solution {
public:
    int fib(int n) {
        if(n<2) return n;
        int f1=0,f2=1;
        for(int i=2;i<=n;++i){
            auto f=f1+f2;
            f1=f2;
            f2=f;
        }
        return f2;
    }
};
// @lc code=end