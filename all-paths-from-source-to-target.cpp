//
// @lc app=leetcode.cn id=211173580 lang=cpp
//
// [211173580] all-paths-from-source-to-target [所有可能的路径]
//
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ret;
        int n=graph.size();
        queue<vector<int>> q;
        q.push({0});
        while(!q.empty()){
            auto cur=q.front();q.pop();
            if(cur.back()==n-1){
                ret.emplace_back(move(cur));
                continue;
            }
            auto & vs=graph[cur.back()];
            for(auto v:vs){
                cur.push_back(v);
                q.push(cur);
                cur.pop_back();
            }
        }
        return ret;
    }
};
// @lc code=end