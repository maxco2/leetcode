//
// @lc app=leetcode.cn id=212583892 lang=cpp
//
// [212583892] edit-distance [编辑距离]
//
class Solution {
public:
    int dp[510][510];
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        if(word1.empty()||word2.empty()) return m+n;
        for(int i=0;i<=m;++i)
        dp[i][0]=i;
        for(int i=0;i<=n;++i)
        dp[0][i]=i;
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                dp[i][j]=min(dp[i][j-1]+1,dp[i-1][j]+1);
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(word1[i-1]==word2[j-1]?0:1));
            }
        }
        return dp[m][n];
    }
};
// @lc code=end