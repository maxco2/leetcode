//
// @lc app=leetcode.cn id=168789834 lang=cpp
//
// [168789834] out-of-boundary-paths [出界的路径数]
//
int dp[55][55][55];
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        memset(dp,0,sizeof(dp));
        auto mod=1000000000+7;
        for(auto nn=1;nn<=N;++nn)
        {
        for(auto ii=0;ii<m;++ii)
        {
            for(auto jj=0;jj<n;++jj)
                {
                    auto tmp=0;
                    if(ii-1<0){
                        tmp+=1;
                        tmp%=mod;
                        
                    }else{
                        tmp+=dp[ii-1][jj][nn-1];
                        tmp%=mod;
                    }
                    if(ii+1>=m){
                        tmp+=1;
                        tmp%=mod;
                        
                    }else{
                        tmp+=dp[ii+1][jj][nn-1];
                        tmp%=mod;
                        
                    }
                    if(jj-1<0){
                        tmp+=1;
                        tmp%=mod;
                        
                    }else{
                        tmp+=dp[ii][jj-1][nn-1];
                        tmp%=mod;
                        
                    }
                    if(jj+1>=n){
                        tmp+=1;
                        tmp%=mod;
                        
                    }else{
                        tmp+=dp[ii][jj+1][nn-1];
                        tmp%=mod;
                        
                    }
                    dp[ii][jj][nn]+=(tmp%mod);
                    dp[ii][jj][nn]%=mod;
                    //printf("dp[%d][%d][%d]=%d\n",ii,jj,nn,dp[ii][jj][nn]);
                }
        }
        }
        return dp[i][j][N]%mod;
    }
};
// @lc code=end