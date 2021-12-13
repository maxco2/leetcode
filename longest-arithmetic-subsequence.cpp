//
// @lc app=leetcode.cn id=168789853 lang=cpp
//
// [168789853] longest-arithmetic-subsequence [最长等差数列]
//
#include <bits/stdc++.h>
using namespace std;
// i,j,k 以i为结尾的以公差为k?j:-j的等差数列最大长度
// dp[i][j][k]
// 1. =>1
// 2. k => res
int dp[1505][500][2];
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        memset(dp, 0, sizeof(dp));
        int res=-1;
        int maxA=-1;
        int minA=1000;
        for(auto n:A)
            maxA=max(maxA,n),minA=min(minA,n);
        int diff=min(maxA-minA+1,500);
        for(int i=0;i<A.size();++i) {
            for(int d=0;d<diff;++d){
                dp[A[i]+500][d][0]=max(1, dp[A[i]+d+500][d][0]+1);
                dp[A[i]+500][d][1]=max(1, dp[A[i]-d+500][d][1]+1);
                res=max(dp[A[i]+500][d][0],res);
                res=max(dp[A[i]+500][d][1],res);
            }
        }
        return res;
    }
};
// @lc code=end