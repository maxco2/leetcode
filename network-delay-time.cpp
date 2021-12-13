//
// @lc app=leetcode.cn id=202247070 lang=cpp
//
// [202247070] network-delay-time [网络延迟时间]
//
const int N=110;
class Solution {
public:

    int g[N][N];
    int dist[N];
    bool st[N];
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        memset(dist,0x3f, sizeof dist);
        memset(g, 0x3f, sizeof g),memset(st,0,sizeof st);
        for(auto & v:times){
            g[v[0]][v[1]]=v[2];
        }
        queue<int> q;
        q.push(k);
        dist[k]=0;
        while(!q.empty()){
            auto t=q.front();q.pop();
            st[t]=false;
            for(int i=1;i<=n;++i){
                if(dist[i]>dist[t]+g[t][i]){
                    dist[i]=dist[t]+g[t][i];
                    if(!st[i]){
                        q.push(i);
                        st[i]=true;
                    }
                }
            }
        }
        int res=0;
        for(int i=1;i<=n;++i){
            if(dist[i]==0x3f3f3f3f){
                return -1;
            }else{
                res=max(res,dist[i]);
            }
        }
        return res;
    }
};
// @lc code=end