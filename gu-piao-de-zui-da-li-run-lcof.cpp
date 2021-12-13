//
// @lc app=leetcode.cn id=172620609 lang=cpp
//
// [172620609] gu-piao-de-zui-da-li-run-lcof [股票的最大利润]
//
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int ret=0;
        int m=prices[0];
        for(auto i=1;i<prices.size();++i){
            if(prices[i]-m>0) ret=max(ret,prices[i]-m);
            m=min(m,prices[i]);
        }
        return ret;
    }
};
// @lc code=end