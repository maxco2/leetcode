//
// @lc app=leetcode.cn id=177069909 lang=cpp
//
// [177069909] number-of-ways-to-stay-in-the-same-place-after-some-steps [停在原地的方案数]
//
int dp[2][501];
class Solution {
public:
    const int mod=1000000000+7;
    //f[s,cur]=f[s-1,cur+1]+f[s-1,cur-1]+f[s-1,cur]
    //f[0,0]=1
    //f[0,!0]=0
    int numWays(int steps, int arrLen) {
        int maxColumn = min(arrLen - 1, steps);
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=steps;++i){
            for(int j=0;j<=maxColumn;++j){
                dp[i%2][j]=dp[(i-1)%2][j];
                if(j-1>=0){
                    dp[i%2][j]+=dp[(i-1)%2][j-1];
                    dp[i%2][j]%=mod;
                }
                if(j+1<=maxColumn){
                    dp[i%2][j]+=dp[(i-1)%2][j+1];
                    dp[i%2][j]%=mod;                    
                }

            }
        }
        return dp[steps%2][0];
    }
};
// @lc code=end