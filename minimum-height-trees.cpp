//
// @lc app=leetcode.cn id=196205059 lang=cpp
//
// [196205059] minimum-height-trees [最小高度树]
//
constexpr int N=2e4+10;
int h[N],e[N],ne[N],pre[N],idx;
bool st[N];
class Solution {
public:
    void add(int a,int b){
        e[idx]=b,ne[idx]=h[a],h[a]=idx++;
    }
    int cd;
    int md;
    void dfs(int t,int d){
        st[t]=true;
        if(d>cd){
            cd=d;
            md=t;
        }
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(!st[j]){
                pre[j]=t;
                dfs(j,d+1);
            }
        }
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};cd=-1;
        memset(st,0,sizeof st);
        memset(h,-1,sizeof h),idx=0;
        for(auto & e:edges){
            int a=e[0],b=e[1];
            add(a,b),add(b,a);
        }
        dfs(0,0);
        cd=-1;
        auto p1=md;
        memset(st,0,sizeof st);
        dfs(md,0);
        auto p2=md;
        vector<int> ret;
        while(true){
            ret.push_back(p2);
            p2=pre[p2];
            if(p2==p1){
                ret.push_back(p2);
                break;
            }
        }
        int sz=ret.size();
        if(sz%2==0){
            int l1=sz/2;
            int l2=l1-1;
            return {ret[l1],ret[l2]};
        }else{
            return {ret[sz/2]};
        }
    }
};
// @lc code=end