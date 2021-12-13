//
// @lc app=leetcode.cn id=168789789 lang=cpp
//
// [168789789] min-cost-climbing-stairs [使用最小花费爬楼梯]
//
//cost[i]+=min(cost[i+1],cost[i+2])
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size=cost.size();
        for(int i=cost.size()-3;i>=0;i--)
        {
            cost[i]+=min(cost[i+1],cost[i+2]);
        }
        return min(cost[0],cost[1]);
    }
};
// @lc code=end