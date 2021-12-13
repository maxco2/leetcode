//
// @lc app=leetcode.cn id=168705356 lang=cpp
//
// [168705356] number-of-longest-increasing-subsequence [最长递增子序列的个数]
//
int dp[2005];
int l[2005];
class Solution {
public:
    // dp[k]以n[k]为结尾的最大长度
    int findNumberOfLIS(vector<int>& nums) {
        memset(dp,0,sizeof(dp));
        memset(l,0,sizeof(l));
        dp[0]=1;
        l[0]=1;
        int max_len=1;
        for(auto i=1;i<nums.size();++i){
            dp[i]=1;
            for(auto j=0;j<i;j++){
                if(nums[j]<nums[i])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                    max_len=max(max_len,dp[i]);
                }
            }
            if(dp[i]!=1){
            for(auto j=0;j<i;j++){
                //l[j]以num[j]为结尾且长度为dp[j]的个数
                if(dp[j]+1==dp[i]&&nums[j]<nums[i])
                    l[i]+=l[j];
            }
            }else{
                l[i]=1;
            }
        }
        int res=0;
       // printf("max len:%d\n",max_len);
        for(auto i=0;i<nums.size();++i){
            if(dp[i]==max_len){
                res+=l[i];
            }
        }
        return res;
    }
};
// @lc code=end