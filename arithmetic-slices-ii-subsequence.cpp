//
// @lc app=leetcode.cn id=205703107 lang=cpp
//
// [205703107] arithmetic-slices-ii-subsequence [等差数列划分 II - 子序列]
//
class Solution {
public:
    using ll=long long;
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<ll,int>> dp(n);
        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                ll d=(ll)nums[i]-nums[j];
                auto it=dp[j].find(d);
                if(it!=dp[j].end()){
                    dp[i][d]+=it->second+1;
                    ans+=it->second;
                }else{
                    dp[i][d]++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end