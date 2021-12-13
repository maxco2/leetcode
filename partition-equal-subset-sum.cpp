//
// @lc app=leetcode.cn id=168789839 lang=cpp
//
// [168789839] partition-equal-subset-sum [分割等和子集]
//
int dp[10005];
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // sum(p)=sum(q)
        // sum(p)+sum(q)=sum
        // sum(p)=sum/2
        int sum=0;
        for(auto n:nums)sum+=n;
        if(sum%2!=0) return 0;
        //memset(dp,0,sizeof(dp));
        dp[0]=0;
        for(int i=1;i<=sum/2;++i) dp[i]=INT_MIN;
        for(auto n:nums){
            for(int j=sum/2;j>=n;j--){
                dp[j]=max(dp[j],dp[j-n]+n);
            }
        }
        return dp[sum/2]>0;
    }
};
// @lc code=end