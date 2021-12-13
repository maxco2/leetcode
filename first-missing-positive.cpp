//
// @lc app=leetcode.cn id=193455194 lang=cpp
//
// [193455194] first-missing-positive [缺失的第一个正数]
//
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> mem;
        int res=1;
        for(auto n:nums){
            mem.insert(n);
            if(mem.count(res)){
                do{
                    res++;
                }while(mem.count(res));
            }
        }
        return res;
    }
};
// @lc code=end