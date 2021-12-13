//
// @lc app=leetcode.cn id=179100653 lang=cpp
//
// [179100653] powx-n [Pow(x, n)]
//
class Solution {
public:
    double myPoww(double x, long long n){
        if(n<0) return myPoww(1.0/x,-n);
        double res=1;
        while(n){
            if(n&1) res*=x;
            n>>=1;
            x*=x;
        }
        return res;
    }
    
    
    double myPow(double x, int n) {
        long long nb=n;
        return myPoww(x,nb);

    }
};
// @lc code=end