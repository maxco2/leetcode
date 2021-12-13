//
// @lc app=leetcode.cn id=185935467 lang=cpp
//
// [185935467] ones-and-zeroes [一和零]
//
class Solution {
public:
    int dp[105][105];
    // dp[k][i][j]=max(dp[k-1][i][j],dp[k-1][i-z][j-o]+1);
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> v;
        memset(dp,0,sizeof(dp));
        for(auto& s:strs){
            int z=0;
            int o=0;
            for(auto c:s){
                if(c=='0') z+=1;
                else o+=1;
            }
            v.push_back({z,o});
        }
        for(auto & p:v){
            int z=p.first;
            int o=p.second;
            for(int i=m;i>=z;--i){
                for(int j=n;j>=o;--j){
                    dp[i][j]=max(dp[i][j],dp[i-z][j-o]+1);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end