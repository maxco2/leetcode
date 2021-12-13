//
// @lc app=leetcode.cn id=171040326 lang=cpp
//
// [171040326] search-a-2d-matrix [搜索二维矩阵]
//
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int curm=0;
        int curn=n-1;
        while(curm<m&&curn>=0){
            if(matrix[curm][curn]==target){
                return true;
            }else if(matrix[curm][curn]<target){
                curm+=1;
            }else{
                curn-=1;
            }
        }
        return false;
    }
};
// @lc code=end