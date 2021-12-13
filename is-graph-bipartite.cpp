//
// @lc app=leetcode.cn id=196189799 lang=cpp
//
// [196189799] is-graph-bipartite [判断二分图]
//
class Solution {
public:
    int color[110];
    bool dfs(int t,vector<vector<int>>& graph,int cr){
        color[t]=cr;
        auto& v=graph[t];
        for(int i=0;i<v.size();++i){
            auto j=v[i];
            if(color[j]==0){
                if(!dfs(j,graph,3-cr)){
                    return false;
                }
            }else if(color[j]==cr){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        memset(color,0,sizeof color);
        for(int i=0;i<n;++i){
            if(!color[i]){
                if(!dfs(i,graph,1)){
                    return false;
                }
            }
        }
        return true;
        
    }
};
// @lc code=end