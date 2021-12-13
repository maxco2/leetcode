//
// @lc app=leetcode.cn id=201475888 lang=cpp
//
// [201475888] permutations-ii [全排列 II]
//
class Solution {
public:
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ret;
        do ret.push_back(nums); while(next_permutation(nums.begin(),nums.end()));
        return ret;
    }

};
// @lc code=end