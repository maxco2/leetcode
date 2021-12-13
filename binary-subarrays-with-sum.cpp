//
// @lc app=leetcode.cn id=193451235 lang=cpp
//
// [193451235] binary-subarrays-with-sum [和相同的二元子数组]
//
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum=0;
        int res=0;
        unordered_map<int,int> mem;
        mem.insert({0,1});
        for(auto& n:nums){
            sum+=n;
            if(mem.count(sum-goal)) res+=mem[sum-goal];
            n=sum;
            mem[sum]++;
        }
        return res;
        

    }
};
// @lc code=end