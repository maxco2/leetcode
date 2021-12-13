//
// @lc app=leetcode.cn id=194613111 lang=cpp
//
// [194613111] subarray-sum-equals-k [和为 K 的子数组]
//
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mem;
        mem.insert({0,1});
        int sum=0,res=0;
        for(auto& n:nums){
            sum+=n;
            n=sum;
            if(mem.count(n-k)){
                res+=mem[n-k];
            }
            mem[n]++;
        }
        return res;
    }
};
// @lc code=end