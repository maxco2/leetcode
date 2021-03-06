//
// @lc app=leetcode.cn id=175296427 lang=cpp
//
// [175296427] li-wu-de-zui-da-jie-zhi-lcof [礼物的最大价值]
//
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=1;i<m;++i) grid[i][0]+=grid[i-1][0];
        for(int j=1;j<n;++j) grid[0][j]+=grid[0][j-1];
        for(int i=1;i<m;++i)
        {
            for(int j=1;j<n;++j){
                grid[i][j]+=max(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid.back().back();
    }
};
// @lc code=end