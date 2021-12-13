//
// @lc app=leetcode.cn id=177639458 lang=cpp
//
// [177639458] russian-doll-envelopes [俄罗斯套娃信封问题]
//
class Solution {
public:
    // dp[i] = {dp[j]+1, nums[j] [w,h]<nums[i] [w,h]   0<=j<i}
    int dp[5005];
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        fill(begin(dp),end(dp),1);
        //memset(dp,0,sizeof(dp));
        dp[0]=1;
        sort(envelopes.begin(),envelopes.end(),[](const vector<int>& v1,const vector<int> & v2){
            if(v1[0]==v2[0]){
                return v1[1]<v2[1];
            }
            return v1[0]<v2[0];
        });
        int ret=1;
        for(auto i=1;i<envelopes.size();++i){
            for(auto j=0;j<i;++j){
                if(envelopes[j][0]<envelopes[i][0]&&envelopes[j][1]<envelopes[i][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                    ret=max(ret,dp[i]);
                }
            }
        }
        return ret;
    }
};
// @lc code=end