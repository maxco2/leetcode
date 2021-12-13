//
// @lc app=leetcode.cn id=197723157 lang=cpp
//
// [197723157] frequency-of-the-most-frequent-element [最高频元素的频数]
//
class Solution {
public:
    int n;
    bool check(int mid,vector<long long>& pre,vector<int>& nums,int k){
        for(int i=n;i>=mid;--i){
            if((long long)mid*nums[i-1]-pre[i]+pre[i-mid]<=k)
            return true;
        }
        return false;
    }

    int maxFrequency(vector<int>& nums, int k) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> pre(n+1,0);
        for(int i=1;i<=n;++i)
        pre[i]=pre[i-1]+nums[i-1];
        int l=1;
        int r=n;
        int ans=l;
        while(l<=r){
            int mid=l+r>>1;
            if(check(mid,pre,nums,k)) ans=mid,l=mid+1;
            else r=mid-1;
        }
        return ans;
    }
};
// @lc code=end