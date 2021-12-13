//
// @lc app=leetcode.cn id=186528847 lang=cpp
//
// [186528847] number-of-islands [岛屿数量]
//
class Solution {
public:
    bool vst[305][305];
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    int numIslands(vector<vector<char>>& grid) {
        memset(vst,0,sizeof(vst));
        queue<pair<int,int>> q;
        int ret=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(!vst[i][j]&&grid[i][j]=='1'){
                    q.push({i,j});vst[i][j]=true;
                    ret+=1;
                    while(!q.empty()){
                        auto cur=q.front();
                        q.pop();
                        auto x=cur.first;
                        auto y=cur.second;
                        for(int k=0;k<4;++k){
                            int nx=x+dx[k];
                            int ny=y+dy[k];
                            if(nx>=0&&nx<m&&ny>=0&&ny<n&&grid[nx][ny]=='1'&&!vst[nx][ny]){
                                q.push({nx,ny});
                                vst[nx][ny]=true;
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }
};
// @lc code=end