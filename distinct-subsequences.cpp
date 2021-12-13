//
// @lc app=leetcode.cn id=177441503 lang=cpp
//
// [177441503] distinct-subsequences [不同的子序列]
//
class Solution {
public:
    //dp[i][j] 以0..i的子串s‘,和0..j子串t’最大长度
    //dp[i][j]=dp[i-1][j-1](s[i]==t[j])
    //          =dp[i-1][j](s[i]!=t[j])
    unsigned dp[2][1000];
    int numDistinct(string s, string t) {
        if(s.empty()||t.empty()) return 0;
        if(s.size()<t.size()) return 0;
        //vector<vector<unsigned>> dp(2,vector<unsigned>(t.size(),0));
        memset(dp,0,sizeof(dp));
        //cout<<"fuck"<<endl;
        if(s[0]==t[0]) dp[0][0]=1;
        for(int i=1;i<s.size();++i){
            if(s[i]==t[0]){
                dp[i%2][0]=dp[(i-1)%2][0]+1;
            }else{
                dp[i%2][0]=dp[(i-1)%2][0];
            }
            for(int j=1;j<=i&&j<t.size();++j){
                if(s[i]==t[j]){
                    dp[i%2][j]=dp[(i-1)%2][j-1]+dp[(i-1)%2][j];//?
                }else{
                    dp[i%2][j]=dp[(i-1)%2][j];
                }
            }
        }
        return dp[(s.size()-1)%2][t.size()-1];
    }
};

// @lc code=end