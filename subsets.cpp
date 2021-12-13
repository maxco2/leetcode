//
// @lc app=leetcode.cn id=170451452 lang=cpp
//
// [170451452] subsets [子集]
//
class Solution {
public:
    void dfs(vector<vector<int>>& ret,vector<int>&nums,int idx,vector<int>& cur){
        if(idx<nums.size()){
            auto sz=cur.size();
            dfs(ret,nums,idx+1,cur);
            while(cur.size()!=sz) cur.pop_back();
            cur.push_back(nums[idx]);
            dfs(ret,nums,idx+1,cur);
        }else{
            ret.push_back(cur);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> cur;
        dfs(ret,nums,0,cur);
        return ret;
    }
};
// @lc code=end