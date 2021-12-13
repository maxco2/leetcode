//
// @lc app=leetcode.cn id=178848292 lang=cpp
//
// [178848292] jian-sheng-zi-ii-lcof [剪绳子 II]
//
constexpr int mod=(int)(1e9)+7;
class Solution {
public:
    //m1+...+mm=n;
    //max m1*m2...*mm
    //>=n sqrt(res,n);
    long long mypow(long long root,int ex){
        long long res=1;
        while(ex){
            if(ex&1) res=(res*root)%mod;
            ex>>=1;
            root=(root*root)%mod;
        }
        return res%mod;
    }
    int cuttingRope(int n) {
        if (n <= 3) {
            return n - 1;
        }
        int quotient = n / 3;
        int remainder = n % 3;
        if (remainder == 0) {
            return mypow(3, quotient);
        } else if (remainder == 1) {
            return (mypow(3, quotient - 1) * 4)%mod;
        } else {
            return (mypow(3, quotient) * 2)%mod;
        }
    }
};
// @lc code=end