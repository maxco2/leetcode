//
// @lc app=leetcode.cn id=186760117 lang=cpp
//
// [186760117] merge-intervals [合并区间]
//
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const auto& a,const auto& b){return a[0]<b[0];});
        vector<vector<int>> ret;
        int l=intervals[0][0];
        int r=intervals[0][1];
        ret.push_back({l,r});
        for(int i=1;i<intervals.size();++i){
            if(intervals[i][0]<=r){
                r=max(r,intervals[i][1]);
                ret.back()[1]=r;
            }else{
                l=intervals[i][0];
                r=intervals[i][1];
                ret.push_back({l,r});
            }
        }
        return ret;
    }
};
// @lc code=end