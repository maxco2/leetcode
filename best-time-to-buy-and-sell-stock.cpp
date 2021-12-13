//
// @lc app=leetcode.cn id=186888640 lang=cpp
//
// [186888640] best-time-to-buy-and-sell-stock [买卖股票的最佳时机]
//
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        auto sz=prices.size();
        vector<int> b(sz,0);
        vector<int> m(sz,INT_MIN);
        for(int i=0;i<sz;++i)
            if(i==0)
                m[i]=prices[i];
            else
            {
                m[i]=min(prices[i],m[i-1]);
                b[i]=max(prices[i]-m[i-1],b[i-1]);
            }
        return b[sz-1];
     //b[1,n]=max(n-min[1,n-1],b[1,n-1])
        //min[1,n]=min(m[1,n-1],n);
    }
};
// @lc code=end