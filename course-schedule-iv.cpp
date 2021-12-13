//
// @lc app=leetcode.cn id=216250637 lang=cpp
//
// [216250637] course-schedule-iv [课程表 IV]
//
class Solution {
public:
static const int N=110;
    int g[N][N];
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        memset(g,0x3f,sizeof g);
        for(auto& v:prerequisites){
            g[v[0]][v[1]]=1;
        }
        for(int k=0;k<n;++k){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
                }
            }
        }
        vector<bool> ret;
        for(auto& v:queries){
            //printf("%d->%d:%d\n",v[0],v[1],g[v[0]][v[1]]);
            ret.push_back(g[v[0]][v[1]]<0x3f3f3f3f/2);
        }
        return ret;
    }
};
// @lc code=end