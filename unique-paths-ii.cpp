//
// @lc app=leetcode.cn id=168789757 lang=cpp
//
// [168789757] unique-paths-ii [不同路径 II]
//
/* Unique Paths II
 * 
 * [Medium] [AC:35.2% 348.9K of 990.7K] [filetype:cpp]
 * 
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 * 
 * An obstacle and space is marked as 1 and 0 respectively in the grid.
 * 
 * Example 1:
 * 
 * Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 * 
 * Output: 2
 * 
 * Explanation: There is one obstacle in the middle of the 3x3 grid above.
 * 
 * There are two ways to reach the bottom-right corner:
 * 
 * 1. Right -> Right -> Down -> Down
 * 
 * 2. Down -> Down -> Right -> Right
 * 
 * Example 2:
 * 
 * Input: obstacleGrid = [[0,1],[0,0]]
 * 
 * Output: 1
 * 
 * Constraints:
 * 
 * m == obstacleGrid.length
 * 
 * n == obstacleGrid[i].length
 * 
 * 1 <= m, n <= 100
 * 
 * obstacleGrid[i][j] is 0 or 1.
 * 
 * [End of Description] */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         int R = obstacleGrid.size();
        int C = obstacleGrid[0].size();

        // If the starting cell has an obstacle, then simply return as there would be
        // no paths to the destination.
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        // Number of ways of reaching the starting cell = 1.
        obstacleGrid[0][0] = 1;

        // Filling the values for the first column
        for (int i = 1; i < R; i++) {
            obstacleGrid[i][0] = (obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1) ? 1 : 0;
        }

        // Filling the values for the first row
        for (int i = 1; i < C; i++) {
            obstacleGrid[0][i] = (obstacleGrid[0][i] == 0 && obstacleGrid[0][i - 1] == 1) ? 1 : 0;
        }

        // Starting from cell(1,1) fill up the values
        // No. of ways of reaching cell[i][j] = cell[i - 1][j] + cell[i][j - 1]
        // i.e. From above and left.
        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                if (obstacleGrid[i][j] == 0) {
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                } else {
                    obstacleGrid[i][j] = 0;
                }
            }
        }

        // Return value stored in rightmost bottommost cell. That is the destination.
        return obstacleGrid[R - 1][C - 1];
    
    }
};

// @lc code=end