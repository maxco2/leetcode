//
// @lc app=leetcode.cn id=168789766 lang=cpp
//
// [168789766] dungeon-game [地下城游戏]
//
 // 为什么不能正堆,即从左上到右下,因为勇士到达不同位置所需要最少血量路线未必重合.
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int maxm=dungeon.size();
        int maxn=dungeon[0].size();
        for(auto j=maxn-1;j>=0;--j)
            for(auto i=maxm-1;i>=0;--i)
            {
                int right=INT_MAX;
                int down=INT_MAX;

                if(i+1<maxm)
                    right=dungeon[i+1][j];
                if(j+1<maxn)
                    down=dungeon[i][j+1];
                if(i+1>=maxm&&j+1>=maxn)
                    right=1;
                dungeon[i][j]=max(min({right,down})-dungeon[i][j],1);
            }
        return dungeon[0][0];
    }
};
//
//    [[-2,-3,6],[-5,-10,6],[10,6,6]]
// @lc code=end