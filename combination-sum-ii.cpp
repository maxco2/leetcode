//
// @lc app=leetcode.cn id=177192096 lang=cpp
//
// [177192096] combination-sum-ii [组合总和 II]
//
class Solution {
public:
    vector<vector<int>> ret;
    void dfs(vector<int>& candidates,int remain,int idx,vector<int>& c){
        if(idx==candidates.size()){
            return;
        }

        {
            auto cur=candidates[idx];
            if(cur==remain){
                c.push_back(cur);
                ret.push_back(c);
                c.pop_back();
                return;
            }
            if(cur<remain){
                c.push_back(cur);
                dfs(candidates,remain-cur,idx+1,c);
                c.pop_back();
                while(idx<candidates.size()&&candidates[idx]==cur)
                    idx++;
                dfs(candidates,remain,idx,c);
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        ret.clear();
        vector<int> c;
        dfs(candidates,target,0,c);
        return ret;
    }
};
// @lc code=end