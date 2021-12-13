//
// @lc app=leetcode.cn id=191669366 lang=cpp
//
// [191669366] maximum-ice-cream-bars [雪糕的最大数量]
//
//int dp[100000001];
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int res=0;
        for(auto c:costs){
            if(coins-c>=0){
                res+=1;
                coins-=c;
            }else{
                break;
            }
        }
        return res;
    }
};
// @lc code=end