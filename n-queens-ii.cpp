//
// @lc app=leetcode.cn id=180263474 lang=cpp
//
// [180263474] n-queens-ii [N皇后 II]
//
class Solution {
public:

    int ret;
    bool col[9];
    bool l[20];
    bool r[20];
    int n;
    void dfs(int row,int res=0){
    if(res==n){
        ret+=1;
        return;
    }
    if(row==n) return;
    for (int j = 0; j < n; j ++ ){
        if(!col[j]&&!l[row-j+n-1]&&!r[row+j]){
            col[j]=true;
            l[row-j+n-1]=true;
            r[row+j]=true;
            dfs(row+1,res+1);
            col[j]=false;
            l[row-j+n-1]=false;
            r[row+j]=false;
        }
    }
    }


    int totalNQueens(int n) {
        this->n = n;
        memset(col,0,sizeof(col));
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        ret=0;
        dfs(0);
        return ret;
    }
};
// @lc code=end