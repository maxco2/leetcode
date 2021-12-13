//
// @lc app=leetcode.cn id=177793580 lang=cpp
//
// [177793580] ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof [把数字翻译成字符串]
//
class Solution {
public:
    //dp[i] ith 0<=j<=25 
    // dp[i]=dp[i-2] if i-1,i is valid char  + dp[i-1]
    long dp[35];
    int translateNum(int num) {
        memset(dp,0,sizeof(dp));
        stringstream ss;
        ss<<num;
        auto s=ss.str();
        dp[0]=1;
        for(int i=1;i<s.size();++i){
            if(i>=1&& (s[i-1]-'0')*10+(s[i]-'0')<=25&&(s[i-1]-'0')*10+(s[i]-'0')>=10){
                if(i>=2)
                dp[i]=dp[i-2];
                else
                dp[i]=1;
            }
            dp[i]+=dp[i-1];
        }
        return dp[s.size()-1];
    }
};
// @lc code=end