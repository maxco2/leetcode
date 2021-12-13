//
// @lc app=leetcode.cn id=186437080 lang=cpp
//
// [186437080] pacific-atlantic-water-flow [太平洋大西洋水流问题]
//
class Solution {
public:
    int vst[155][155];
    bool added[155][155];
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        if(m==1&&n==1) return {{0,0}};
        vector<vector<int>> ret;
        memset(added,0,sizeof(added));
        queue<pair<int,int>> q;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        for(int i=0;i<m;++i){
            q.push({i,0});vst[i][0]=1;
        }
        for(int j=1;j<n;++j){
            q.push({0,j});vst[0][j]=1;
        }
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            auto x=cur.first;
            auto y=cur.second;
            auto h=heights[x][y];
            for(int i=0;i<4;++i){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0&&nx<m&&ny>=0&&ny<n&&!vst[nx][ny]){
                    auto nh=heights[nx][ny];
                    if(h<=nh){
                        q.push({nx,ny});
                        vst[nx][ny]=1;
                    }
                }
            }
        }
        for(int i=0;i<m;++i){
            if(vst[i][n-1]==1) ret.push_back({i,n-1}),added[i][n-1]=true;
            q.push({i,n-1});vst[i][n-1]=2;
        }
        for(int j=0;j<n-1;++j){
            if(vst[m-1][j]==1) ret.push_back({m-1,j}),added[m-1][j]=true;
            q.push({m-1,j});vst[m-1][j]=2;
        }
        
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            auto x=cur.first;
            auto y=cur.second;
            auto h=heights[x][y];
            for(int i=0;i<4;++i){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0&&nx<m&&ny>=0&&ny<n){
                    auto nh=heights[nx][ny];
                    if(h<=nh&&vst[nx][ny]!=2){
                        if(vst[nx][ny]+vst[x][y]==3&&!added[nx][ny])ret.push_back({nx,ny}),added[nx][ny]=true;
                        q.push({nx,ny});
                        vst[nx][ny]=2;
                    }
                }
            }
        }

        return ret;
    }
};
// @lc code=end