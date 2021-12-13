//
// @lc app=leetcode.cn id=203741301 lang=cpp
//
// [203741301] qing-wa-tiao-tai-jie-wen-ti-lcof [青蛙跳台阶问题]
//
class Solution {
public:
static const int N=1e9+7;
    //f[n]=f[n-2]+f[n-1]
    int numWays(int n) {
        if(!n) return 1;
        if(n<=2) return n;
        int f1=1,f2=2;
        for(int i=3;i<=n;++i){
            auto tmp=(f1+f2)%N;
            f1=f2%N;
            f2=tmp;
        }
        return f2;
    }
};
// @lc code=end