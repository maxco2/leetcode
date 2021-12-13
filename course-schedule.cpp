//
// @lc app=leetcode.cn id=192060219 lang=cpp
//
// [192060219] course-schedule [课程表]
//
class Solution {
public:
    static const int N=1e5+10, M=5010;
    int h[N],ne[M],e[M],idx,d[N];
    void add(int a,int b){
        e[idx]=b,ne[idx]=h[a],h[a]=idx++;
    }
    int q[N];
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        memset(h,-1,sizeof h);
        idx=0;
        memset(d,0,sizeof d);
        for(auto &v:prerequisites){
            add(v[0],v[1]);
            ++d[v[1]];
        }
        int hh=0,tt=-1;
        auto n=numCourses;
        for(int i=0;i<n;++i)
        if(!d[i]){
            q[++tt]=i;
        }
        while(hh<=tt){
            auto t=q[hh++];
            for(int i=h[t];i!=-1;i=ne[i]){
                int j=e[i];
                --d[j];
                if(!d[j]){
                    q[++tt]=j;
                }
            }
        }
        return tt==numCourses-1;
    }
};
// @lc code=end