//
// @lc app=leetcode.cn id=186051165 lang=cpp
//
// [186051165] burst-balloons [戳气球]
//
class Solution {
public:
    int dp[505][505]; // 以 i开始，j结尾地闭区间，但不戳破气球i，j
    // dp[i][j]=max_k(dp[i][k]+dp[k][j]+n[k]*n[i]*n[j])  i+1<=k<=j-1 , 最后戳破k
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int sz=nums.size();
        memset(dp,0,sizeof(dp));
        for(int l=3;l<=sz;++l){
            for(int i=0;i+l-1<sz;++i){
                int j=i+l-1;
                for(int k=i+1;k<=j-1;++k){
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]+nums[k]*nums[i]*nums[j]);
                }
            }
        }
        return dp[0][sz-1];
    }
};
// @lc code=end