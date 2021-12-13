//
// @lc app=leetcode.cn id=197941697 lang=cpp
//
// [197941697] unique-binary-search-trees [不同的二叉搜索树]
//
class Solution {
public:
    long long c[41][41];
    void init(){
        for(int i=0;i<=40;++i){
            for(int j=0;j<=i;++j){
                if(!i||!j) {c[i][j]=1;continue;}
                c[i][j]=c[i-1][j-1]+c[i-1][j];
            }
        }
    }
    int numTrees(int n) {
        memset(c,0,sizeof c);
        init();
        return c[2*n][n]/(n+1);
    }
};
// @lc code=end