//
// @lc app=leetcode.cn id=169659110 lang=cpp
//
// [169659110] er-wei-shu-zu-zhong-de-cha-zhao-lcof [二维数组中的查找]
//
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int m=matrix.size();
        int n=matrix[0].size();
        int curm=0;
        int curn=n-1;
        while(curm<m&&curn>=0){
            auto cur=matrix[curm][curn];
            if(cur==target){
                return true;
            }else if(cur<target){
                curm+=1;
            }else{
                curn-=1;
            }
        }
        return false;
    }
};
// @lc code=end