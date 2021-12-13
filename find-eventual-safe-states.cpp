//
// @lc app=leetcode.cn id=203523191 lang=cpp
//
// [203523191] find-eventual-safe-states [找到最终的安全状态]
//
class Solution {
public:
    static const int N=1e4+10,M=1e4*4+10;
    int h[N],e[M],ne[M],idx,d[N];
    int q[N];
    void add(int a,int b){
        e[idx]=b,ne[idx]=h[a],h[a]=idx++;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        memset(h,-1,sizeof h);idx=0;memset(d,0,sizeof d);
        int t=0;
        for(auto&v:graph){
            for(auto c:v){
                add(c,t);
                ++d[t];
            }
            t++;
        }
        int hh=0,tt=-1;
        for(int i=0;i<n;++i){
            if(!d[i]){
                q[++tt]=i;
            }
        }
        while(hh<=tt){
            auto t=q[hh++];
            for(int i=h[t];~i;i=ne[i]){
                int j=e[i];
                if(--d[j]==0){
                    q[++tt]=j;
                }
            }
        }
        vector<int> ret(q,q+1+tt);sort(ret.begin(),ret.end());
        return ret;
    }
};
// @lc code=end