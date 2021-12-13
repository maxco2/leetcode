//
// @lc app=leetcode.cn id=188156450 lang=cpp
//
// [188156450] count-sub-islands [统计子岛屿]
//
class Solution {
public:
    bool vst[505][505];
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        int m=g1.size();
        int n=g1[0].size();
        memset(vst,0,sizeof(vst));
        int ret=0;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(!vst[i][j]&&g2[i][j]==1){
                    bool res=(g1[i][j]==g2[i][j]);
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        auto cur=q.front();
                        q.pop();
                        auto x=cur.first;
                        auto y=cur.second;
                        for(int k=0;k<4;++k){
                            auto nx=x+dx[k];
                            auto ny=y+dy[k];
                            if(nx>=0&&nx<m&&ny>=0&&ny<n&&!vst[nx][ny]&&g2[nx][ny]==1){
                                vst[nx][ny]=true;
                                res=res&&(g2[nx][ny]==g1[nx][ny]);
                                q.push({nx,ny});
                            }
                        }
                    }
                    if(res){
                        ret+=1;
                    }
                }
            }
        }
        return ret;
    }
};
// @lc code=end