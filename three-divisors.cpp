//
// @lc app=leetcode.cn id=201910691 lang=cpp
//
// [201910691] three-divisors [三除数]
//
class Solution {
public:
    bool isThree(int n) {
        int res=0;
        for (int i = 1; i <= n / i; i ++ )
        if (n % i == 0)
        {
            res++;
            if (i != n / i) res++;
        }
        return res==3;

    }
};
// @lc code=end