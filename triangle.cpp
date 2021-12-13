//
// @lc app=leetcode.cn id=168789765 lang=cpp
//
// [168789765] triangle [三角形最小路径和]
//
#include <vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        auto size=triangle.size();
        int res=200*200;
        for(auto i=1;i<triangle.size();++i)
        {
            auto last=triangle[i].size()-1;
            triangle[i][0]+=triangle[i-1][0];
            for(auto j=1;j<last;++j)
            {
                triangle[i][j]+=min(triangle[i-1][j-1],
                        triangle[i-1][j]);
            }
            triangle[i][last]+=triangle[i-1][last-1];
        }
        for(auto i=0;i<triangle[size-1].size();++i)
            res=min(res,triangle[size-1][i]);
        return res;
    }
};
// @lc code=end