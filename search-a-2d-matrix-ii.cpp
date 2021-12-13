//
// @lc app=leetcode.cn id=169233549 lang=cpp
//
// [169233549] search-a-2d-matrix-ii [搜索二维矩阵 II]
//
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int cm=0;
        int cn=n-1;
        while(cn>=0&&cm<m){
            if(matrix[cm][cn]>target){
                cn-=1;
            }else if(matrix[cm][cn]==target){
                return true;
            }else{
                cm+=1;
            }
        }
        return false;
    }
};
// @lc code=end