//
// @lc app=leetcode.cn id=193885289 lang=cpp
//
// [193885289] maximal-square [最大正方形]
//
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
            if(matrix.empty()) return 0;
        if(matrix[0].empty()) return 0;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int res=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(matrix[i][j]=='0'){
                    dp[i][j]=0;
                    continue;
                }
                if(i-1>=0&&j-1>=0)
                dp[i][j]=dp[i-1][j-1];
                if(j-1>=0)
                dp[i][j]=min(dp[i][j],dp[i][j-1]);
                if(i-1>=0)
                dp[i][j]=min(dp[i][j],dp[i-1][j]);
                dp[i][j]+=1;
                res=max(res,dp[i][j]);
            }
        }
        return res*res;
    }
};
// @lc code=end