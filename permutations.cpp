//
// @lc app=leetcode.cn id=177197514 lang=cpp
//
// [177197514] permutations [全排列]
//
class Solution {
public:
    vector<vector<int>> ret;
    bool t[6];
    void dfs(vector<int>& nums,int cur,vector<int>& n){
        if(cur==nums.size()){
            ret.push_back(n);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(!t[i]){
                t[i]=true;
                n.push_back(nums[i]);
                dfs(nums,cur+1,n);
                t[i]=false;
                n.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        ret.clear();
        memset(t,0,sizeof(t));
        vector<int> n;
        dfs(nums,0,n);
        return ret;

    }
};
// @lc code=end