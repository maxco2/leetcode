//
// @lc app=leetcode.cn id=177194056 lang=cpp
//
// [177194056] combination-sum [组合总和]
//
class Solution {
public:
    vector<vector<int>> ret;
    void dfs(vector<int>& candidates,int idx,int remain,vector<int>& c){
        if(remain==0){
            ret.push_back(c);
            return;
        }
        if(idx==candidates.size()) return;
        auto cur=candidates[idx];
        dfs(candidates,idx+1,remain,c);
        for(int i=1;i<=remain/cur;++i){
            c.push_back(cur);
            dfs(candidates,idx+1,remain-i*cur,c);
        }
        for(int i=1;i<=remain/cur;++i) c.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ret.clear();
        sort(candidates.begin(),candidates.end());
        vector<int> c;
        dfs(candidates,0,target,c);
        return ret;
    }
};
// @lc code=end