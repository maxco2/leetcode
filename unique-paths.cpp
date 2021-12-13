//
// @lc app=leetcode.cn id=168789752 lang=cpp
//
// [168789752] unique-paths [不同路径]
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1)
            return 1;
        if(n==1)
            return 1;
        double res=1;
        int q=m-1+n-1;
        for(int i=q;i!=n-1;i--)
            res*=i,res/=(i-(n-1));
        return round(res);
    }
};
// @lc code=end