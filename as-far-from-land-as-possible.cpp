//
// @lc app=leetcode.cn id=186440787 lang=cpp
//
// [186440787] as-far-from-land-as-possible [地图分析]
//
class Solution {
public:
    bool vst[105][105];
    int maxDistance(vector<vector<int>>& grid) {
        int dis=0;
        memset(vst,0,sizeof(vst));
        int m=grid.size();
        int n=grid[0].size();
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                    vst[i][j]=true;
                }
            }
        }
        //如果从海洋多源bfs,无法找到陆地距离最大的
        //如果从陆地多源bfs,队列最后的海洋即是最终解
        if(q.size()==m*n) return -1;
        if(q.empty()) return -1;
        while(!q.empty()){
            auto cur=q.front();
            auto x=cur.first.first;
            auto y=cur.first.second;
            auto cd=cur.second;
            q.pop();
            for(int i=0;i<4;++i){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0&&nx<m&&ny>=0&&ny<n&&!vst[nx][ny]){
                    q.push({{nx,ny},cd+1});
                    vst[nx][ny]=true;
                    dis=max(dis,cd+1);
                }
            }
            
        }
        return dis;
    }
};
// @lc code=end