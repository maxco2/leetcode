//
// @lc app=leetcode.cn id=196534178 lang=cpp
//
// [196534178] number-of-provinces [省份数量]
//
class Solution {
public:
    int p[210];
    int size[210];
    int find(int x){
        if(p[x]!=x) p[x]=find(p[x]);
        return p[x];
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        for(int i=0;i<n;++i) p[i]=i,size[i]=1;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(isConnected[i][j]){
                    int pa=find(i);
                    int pb=find(j);
                    if(pa==pb) continue;
                    p[pa]=pb;
                    size[pb]+=size[pa];
                }
            }
        }
        int res=0;
        unordered_set<int> mem;
        for(int i=0;i<n;++i){
            int pi=find(i);
            if(!mem.count(pi)){
                res+=1;
                mem.insert(pi);
            }
        }
        return res;
    }
};
// @lc code=end