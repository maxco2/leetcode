//
// @lc app=leetcode.cn id=179039425 lang=cpp
//
// [179039425] find-the-duplicate-number [寻找重复数]
//
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 1^2..^n
        // 1^2..x^x..^n => x^y
        if(nums.size()==2) return nums[0];
        sort(nums.begin(),nums.end());
        int last=-1;
        for(auto n:nums){
            if(last==n) return n;
            last=n;
        }
        return -1;

    }
};
// @lc code=end