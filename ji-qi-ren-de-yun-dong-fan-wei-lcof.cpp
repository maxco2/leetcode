//
// @lc app=leetcode.cn id=203749416 lang=cpp
//
// [203749416] ji-qi-ren-de-yun-dong-fan-wei-lcof [机器人的运动范围]
//
class Solution {
public:
#define x first
#define y second
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    bool st[110][110];
    bool check(int nx,int ny,int k){
        int res=0;
        while(nx){
            res+=nx%10;
            nx/=10;
        }
        while(ny){
            res+=ny%10;
            ny/=10;
        }
        return res<=k;
    }
    int movingCount(int m, int n, int k) {
        queue<pair<int,int>> q;memset(st,0,sizeof st);
        q.push({0,0});
        int res=1;
        st[0][0]=true;
        while(q.size()){
            auto cur=q.front();q.pop();
            for(int i=0;i<4;++i){
                int nx=cur.x+dx[i];
                int ny=cur.y+dy[i];
                if(nx>=0&&nx<m&&ny>=0&&ny<n&&!st[nx][ny]&&check(nx,ny,k)){
                    q.push({nx,ny});
                    st[nx][ny]=true;
                    res+=1;
                }
            }
        }
        return res;
    }
};
// @lc code=end