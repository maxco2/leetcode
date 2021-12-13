//
// @lc app=leetcode.cn id=211496417 lang=cpp
//
// [211496417] best-time-to-buy-and-sell-stock-iii [买卖股票的最佳时机 III]
//
class Solution {
public:
    static const int N=1e5+10;
    //int f[N][3][2];
    int maxProfit(vector<int>& p) {
        //f[i][j][0]=max(f[i-1][j-1][1]+p[i],f[i-1][j][0])
        //f[i][j][1]=max(f[i-1][j][0]-p[i],f[i-1][j][1])
        int n=p.size();
        if(p.size()==1){
            return 0;
        }
        vector<vector<vector<int>>> f(n,vector<vector<int>>(3,vector<int>(2,0)));
        f[0][0][1]=-p[0];
        f[0][1][1]=-p[1];
        for(int i=1;i<p.size();++i){
            for(int j=2;j>=1;--j){
                f[i][j][0]=max(f[i-1][j-1][1]+p[i],f[i-1][j][0]);
                f[i][j][1]=max(f[i-1][j][0]-p[i],f[i-1][j][1]);
            }
            f[i][0][1]=max(f[i-1][0][0]-p[i],f[i-1][0][1]);
            f[i][0][0]=f[i-1][0][0];
        }
        //cout<<f.size()<<endl;
        //cout<<f[n-1].size()<<endl;
        //cout<<f[n-1][2].size()<<endl;
        //cout<<f[n-1][2][0]<<endl;
        //cout<<f[n-1][1][0]<<endl;
        return max(f[n-1][2][0],f[n-1][1][0]);
    }
};
// @lc code=end