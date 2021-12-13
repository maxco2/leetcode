//
// @lc app=leetcode.cn id=192058746 lang=cpp
//
// [192058746] chuan-di-xin-xi [传递信息]
//
class Solution {
public:
    //int g[15][15];
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> g(n,vector<int>(n,0x3f3f3f3f));
        for(auto& v:relation)
        {
            g[v[0]][v[1]]=1;
        }
        queue<pair<int,int>> q;
        q.push({0,0});
        int res=0;
        while(!q.empty()){
            auto cur=q.front();q.pop();
            auto t=cur.first;
            auto d=cur.second;
            if(d==k&&t==n-1) {
                res+=1;
                continue;
            }else if(d>=k){
                continue;
            }
            for(int i=0;i<n;++i){
                if(i!=t&&g[t][i]==1){
                    q.push({i,d+1});

                }
            }


        }
        return res;
    }
};
// @lc code=end