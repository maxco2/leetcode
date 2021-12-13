//
// @lc app=leetcode.cn id=194653905 lang=cpp
//
// [194653905] minimum-cost-to-reach-destination-in-time [规定时间内到达终点的最小花费]
//
static const int N=1010,M=N*2;
int h[N],e[M],ne[M],w[M],idx;
int dist[N][N];
bool st[N][N];
class Solution {
public:
    using pii=pair<int,int>;
    void add(int a,int b,int c){
        e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
    }
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& pf) {
        memset(h,-1,sizeof h),idx=0;
        for(auto & v:edges){
            int a=v[0],b=v[1],c=v[2];
            add(a,b,c);
            add(b,a,c);
        }
        int n=pf.size();
        memset(st,0,sizeof st);
        memset(dist,0x3f,sizeof dist);
        dist[0][0]=pf[0];
        queue<pii> q;
        q.push({0,0});
        st[0][0]=true;
        while(q.size()){
            auto cur=q.front();q.pop();
            auto x=cur.first;
            auto y=cur.second;
            st[x][y]=false;
            for(int i=h[x];i!=-1;i=ne[i]){
                int jx=e[i],jy=w[i]+y;
                if(jy>maxTime) continue;
                if(dist[jx][jy]>dist[x][y]+pf[jx]){
                    dist[jx][jy]=dist[x][y]+pf[jx];
                    //printf("point:%d,time:%d,cost:%d\n",jx,jy,dist[jx][jy]);
                    if(!st[jx][jy]){
                        st[jx][jy]=true;
                        q.push({jx,jy});
                    }
                }
            }
        }
        int res=0x3f3f3f3f;
        for(int i=0;i<=maxTime;++i) cout<<dist[n-1][i]<<endl,res=min(res,dist[n-1][i]);
        if(res==0x3f3f3f3f) return -1;
        cout<<res<<endl;
        return res;

    }
};
// @lc code=end