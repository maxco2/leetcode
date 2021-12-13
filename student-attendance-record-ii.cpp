//
// @lc app=leetcode.cn id=214475342 lang=cpp
//
// [214475342] student-attendance-record-ii [学生出勤记录 II]
//
const int MOD=1e9+7;
const int N=1e5+10;
class Solution {
public:
using ull=unsigned long long;
    unsigned long long res;
    int n;
    int dp[N][2][3];
    // dp[cur][1][0]=dp[cur-1][0][l] (l>=0&&l<=2)
    // dp[cur][a][l+1]=dp[cur-1][a][l];(l<2)
    //dp[cur][a][0]=dp[cur-1][a][l];(l<=2)
    //
    void dfs(int cur,int a,int l){
        if(dp[cur][a][l]!=-1){
            //printf("hit\n");
            res+=dp[cur][a][l];
            //res%=MOD;
            return;
        }
        if(cur==n){
            res++;
            return;
        }
        ull d=0;
        ull tmp;
        if(a==0){
            tmp=res;
            dfs(cur+1,1,0);
            d+=res-tmp;
        d%=MOD;

        }
        if(l<2){
            tmp=res;
            dfs(cur+1,a,l+1);
            d+=res-tmp;
        d%=MOD;

        }
        tmp=res;
        dfs(cur+1,a,0);
        d+=res-tmp;
        d%=MOD;
        dp[cur][a][l]=d;
    }
    int checkRecord(int n) {
        memset(dp,-1,sizeof dp);
        res=0;this->n=n;dfs(0,0,0);
        return res%MOD;
    }
};
// @lc code=end