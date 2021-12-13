//
// @lc app=leetcode.cn id=185938867 lang=cpp
//
// [185938867] target-sum [目标和]
//
class Solution {
public:
    //sum(L)-sum(R)=target
    //sum(L)+sum(R)=sum
    //2L=sum+target
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto c:nums) sum+=c;
        if((sum+target)%2==0){
            int t=(sum+target)/2;
            vector<int> v(t+1,0);
            v[0]=1;
            for(auto c:nums){
                for(int i=t;i>=c;--i)
                    v[i]=v[i]+v[i-c];
            }
            return v[t];
        }
        return 0;
    }
};
// @lc code=end