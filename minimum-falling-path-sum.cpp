//
// @lc app=leetcode.cn id=168789799 lang=cpp
//
// [168789799] minimum-falling-path-sum [下降路径最小和]
//
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& m) {
        auto r=m.size();
        auto c=m[0].size();
        for(auto i=1;i<r;++i)
            for(auto j=0;j<c;++j)
            {
               int res=m[i][j]+m[i-1][j];
               if(j-1>=0)
                   res=min(res,m[i][j]+m[i-1][j-1]);
                if(j+1<c)
                    res=min(res,m[i][j]+m[i-1][j+1]);
                m[i][j]=res;
            }
        unsigned k=~0;
        int res=k>>1;
        for(int i=0;i<c;++i){
            res=min(m[r-1][i],res);
        }
        return res;  
    }
};
// @lc code=end