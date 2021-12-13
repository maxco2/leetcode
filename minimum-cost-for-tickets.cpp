//
// @lc app=leetcode.cn id=168789800 lang=cpp
//
// [168789800] minimum-cost-for-tickets [最低票价]
//
class Solution {
public:
    int bse(vector<int>& ds,int v)
    {
        int r=ds.size()-1;
        int l=0;
        int res=l;
        while(l<=r){
            int mid=l+r>>1;
            if(ds[mid]>v)
                res=mid,r=mid-1;
            else
                l=mid+1;
        }
        if(ds[res]>v)
        {
            return res-1;
        }else{
            return -1;
        }
    }
    unordered_map<int,int>  map;
    int dfs(int day,vector<int>& ds,vector<int>&c){
        if(map.find(day)!=map.end())
            return map[day];
        int dp2=c[2],dp1=c[1],dp0=c[0];
#define ADD(dp,l)\
        {\
            auto p0=bse(ds,day-l);\
            if(p0>=0){\
                dp+=dfs(ds[p0],ds,c);\
            }\
        }
        ADD(dp2,30)
        ADD(dp1,7)
        ADD(dp0, 1)

        int res=min({dp0,dp1,dp2});
        map[day]=res;
        return res;
    }
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        auto r=days.size()-1;
        return dfs(days[r],days,cost);
    }
};

// @lc code=end