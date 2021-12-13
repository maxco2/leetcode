//
// @lc app=leetcode.cn id=168789759 lang=cpp
//
// [168789759] minimum-path-sum [最小路径和]
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int maxm=grid.size();
        int maxn=grid[0].size();
        for(int m=1;m<maxm;++m)
            grid[m][0]+=grid[m-1][0];
        for(int n=1;n<maxn;++n)
            grid[0][n]+=grid[0][n-1];
        for(int m=1;m<maxm;++m)
            for(int n=1;n<maxn;++n)
                grid[m][n]+=min(grid[m-1][n],grid[m][n-1]);
        return grid[maxm-1][maxn-1];
    }
};
// @lc code=end