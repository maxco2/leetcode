//
// @lc app=leetcode.cn id=206644940 lang=cpp
//
// [206644940] longest-palindromic-subsequence [最长回文子序列]
//
class Solution {
public:
    int dp[1010][1010];
    int longestPalindromeSubseq(string s) {
        memset(dp,0,sizeof dp);
        for(int d=1;d<=s.size();++d){
            for(int l=0;d-1+l<s.size();++l){
                int r=d-1+l;
                if(d==1){
                    dp[l][r]=1;
                }else if(d==2){
                    dp[l][r]=((s[l]==s[r])?2:1);
                }else{
                    dp[l][r]=max(dp[l+1][r],dp[l][r-1]);
                    dp[l][r]=max(dp[l+1][r-1]+((s[l]==s[r])?2:0),dp[l][r]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};
// @lc code=end