//
// @lc app=leetcode.cn id=196235107 lang=cpp
//
// [196235107] longest-increasing-path-in-a-matrix [矩阵中的最长递增路径]
//
class Solution {
public:
    unordered_map<int,int> mem;
    int m,n;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    int dfs(int x,int y,vector<vector<int>>& matrix){
        int h=x*n+y;
        if(mem.count(h)) 
        {
            return mem[h];
        }
        int res=1;
        for(int i=0;i<4;++i){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&nx<m&&ny>=0&&ny<n&&matrix[x][y]<matrix[nx][ny]){
                res=max(res,dfs(nx,ny,matrix)+1);
            }
        }
        mem[h]=res;
        return res;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        mem.clear();
        m=matrix.size(),n=matrix[0].size();
        int res=1;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                res=max(res,dfs(i,j,matrix));
            }
        }
        return res;
    }
};
// @lc code=end