//
// @lc app=leetcode.cn id=190369665 lang=cpp
//
// [190369665] snakes-and-ladders [蛇梯棋]
//
class Solution {
public:
    int n;
    pair<int,int> toaxis(int i){
        if(n%2==0){
            auto x=n-(i+n-1)/n;
            if(x%2==0)
                return {x,(n-1)-(i-1)%n};
            else
                return {x,(i-1)%n};
        }else{
            auto x=n-(i+n-1)/n;
            if(x%2!=0)
                return {x,(n-1)-(i-1)%n};
            else
                return {x,(i-1)%n};
        }
    }
    static const int N=410;
    int g[N][N];
    int dist[N];
    bool st[N];
    #define debug(x) printf("No %d to axis:(%d,%d)\n",x,toaxis(x).first,toaxis(x).second);
    int snakesAndLadders(vector<vector<int>>& board) {
        n=board.size();
        memset(g,0x3f, sizeof g);
        memset(dist,0x3f ,sizeof dist);
        memset(st,0,sizeof st);
        for(int i=1;i<=n*n;++i){
            auto ax=toaxis(i);
            auto x=ax.first;
            auto y=ax.second;
            for(int j=1;j<=6&&i+j<=n*n;++j){
                auto nax=toaxis(i+j);
                auto nx=nax.first;
                auto ny=nax.second;
                //if(nx>=n||ny>=n||nx<0||ny<0)
                //{cout<<nx<<" "<<ny<<endl;cout<<" x:"<<x<<" y:"<<y<<" No:"<<i<<endl;}
                if(board[nx][ny]==-1){
                    g[i][i+j]=1;
                }else{
                    g[i][board[nx][ny]]=1;
                }
            }
        }
        using pii=pair<int,int>;
        queue<int> q;
        dist[1]=0;
        q.push(1);
        st[1]=true;
        while(!q.empty()){
            auto t=q.front();q.pop();
            st[t]=false;
            for(int i=1;i<=n*n;++i){
                if(dist[i]>dist[t]+g[t][i]){
                    dist[i]=dist[t]+g[t][i];
                    if(!st[i]){
                        q.push(i);
                        st[i]=true;
                    }
                }
            }
        }
        if(dist[n*n]!=dist[0]) return dist[n*n];
        return -1;
    }
};
// @lc code=end