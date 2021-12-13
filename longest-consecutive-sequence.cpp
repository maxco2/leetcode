//
// @lc app=leetcode.cn id=186679634 lang=cpp
//
// [186679634] longest-consecutive-sequence [最长连续序列]
//
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res=0;
        unordered_set<int> mem;
        mem.insert(nums.begin(),nums.end());
        for(auto n:nums){
            if(!mem.count(n-1)){
                int tmp=1;
                while(mem.count(n+1)){
                    tmp+=1;
                    n+=1;
                }
                res=max(res,tmp);
            }
        }
        return res;
    }
};
// @lc code=end