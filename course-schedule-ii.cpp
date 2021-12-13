//
// @lc app=leetcode.cn id=195085488 lang=cpp
//
// [195085488] course-schedule-ii [课程表 II]
//
static const int N=1e5+10, M=5010;
    int h[N],ne[M],e[M],idx,d[N];
    void add(int a,int b){
        e[idx]=b,ne[idx]=h[a],h[a]=idx++;
    }
    int q[N];
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        memset(h,-1,sizeof h);idx=0;
        int hh=0,tt=-1;
        memset(d,0,sizeof d);
        for(auto& v:prerequisites){
            int a=v[1],b=v[0];
            add(a,b);
            ++d[v[0]];
        }
        for(int i=0;i<numCourses;++i){
            if(!d[i]){
                q[++tt]=i;
            }
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
        if(tt==numCourses-1){
            return vector<int>(q,q+numCourses);
        }
        return {};
    }
};
// @lc code=end