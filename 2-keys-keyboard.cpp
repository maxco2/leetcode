//
// @lc app=leetcode.cn id=168789795 lang=cpp
//
// [168789795] 2-keys-keyboard [只有两个键的键盘]
//
//at most n step
// dp[s][buf]=min(dp[s][b!=buf]+1) s==buf
//dp[s][buf]= dp[s-buf][buf]+1
//int dp[1005][1005];
class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,n+1));
        dp[1][0]=0;
        dp[1][1]=1;
        for(int i=2;i<=n;++i)
            for(int j=1;j<=i;++j)
            {
                int res=n+1;
                if(i==j)
                {
                    for(int k=1;k<j;k++)
                        res=min(res,dp[i][k]+1);
                }
                dp[i][j]=min(res,dp[i-j][j]+1);
            }
        int res=n;
        for(int i=1;i<=n;++i)
        {
            res=min(res,dp[n][i]);
        }
        return res;
    }
};
// @lc code=end