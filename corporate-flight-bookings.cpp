//
// @lc app=leetcode.cn id=213375660 lang=cpp
//
// [213375660] corporate-flight-bookings [航班预订统计]
//
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ret(n+1,0);
        for(auto& v:bookings){
            ret[v[0]-1]+=v[2];
            ret[v[1]]-=v[2];
        }
        int sum=0;
        for(int i=0;i<n;++i){
            sum+=ret[i];
            ret[i]=sum;
        }
        ret.pop_back();
        return ret;
    }
};
// @lc code=end