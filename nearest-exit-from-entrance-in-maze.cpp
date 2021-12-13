//
// @lc app=leetcode.cn id=194319956 lang=cpp
//
// [194319956] nearest-exit-from-entrance-in-maze [迷宫中离入口最近的出口]
//
class Solution {
public:
    bool vst[110][110];
    int nearestExit(vector<vector<char>>& maze, vector<int>& ee) {
        memset(vst,0,sizeof(vst));
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        queue<pair<pair<int,int>,int>> q;
        int m=maze.size();
        int n=maze[0].size();
        q.push({{ee[0],ee[1]},0});
        vst[ee[0]][ee[1]]=true;
        while(!q.empty()){
            auto cur=q.front();q.pop();
            auto x=cur.first.first;
            auto y=cur.first.second;
            auto d=cur.second;
            for(int i=0;i<4;++i){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0&&nx<m&&ny>=0&&ny<n){
                    if(!vst[nx][ny]&&maze[nx][ny]=='.'){
                        q.push({{nx,ny},d+1});
                        vst[nx][ny]=true;
                    }
                }else if(d!=0){
                    return d;
                }
            }
        }
        return -1;
    }
};
// @lc code=end