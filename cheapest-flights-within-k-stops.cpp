//
// @lc app=leetcode.cn id=210805678 lang=cpp
//
// [210805678] cheapest-flights-within-k-stops [K 站中转内最便宜的航班]
//
class Solution {
public:
    int dist[110];
    int dist2[110];
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        memset(dist,0x3f,sizeof dist);
        dist[src]=0;
        for(int i=0;i<k+1;++i){
            memcpy(dist2,dist,sizeof dist);
            for(auto& v:flights){
                if(dist[v[1]]>dist2[v[0]]+v[2])
                dist[v[1]]=dist2[v[0]]+v[2];
            }
        }
        if(dist[dst]>dist[109]/2){
            return -1;
        }
        return dist[dst];
    }
};
// @lc code=end