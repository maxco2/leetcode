//
// @lc app=leetcode.cn id=180254968 lang=cpp
//
// [180254968] n-queens [N 皇后]
//
class Solution {
public:
    vector<vector<string>> ret;
    vector<int> res;
    bool col[9];
    bool l[20];
    bool r[20];
    int n;
    void dfs(int row){
    if(res.size()==n){
        vector<string> tmp(n,string(n,'.'));
        for(int i=0;i<n;++i) tmp[i][res[i]]='Q';
        ret.emplace_back(std::move(tmp));
        return;
    }
    if(row==n) return;
    for (int j = 0; j < n; j ++ ){
        if(!col[j]&&!l[row-j+n-1]&&!r[row+j]){
            col[j]=true;
            l[row-j+n-1]=true;
            r[row+j]=true;
            res.push_back(j);
            dfs(row+1);
            col[j]=false;
            l[row-j+n-1]=false;
            r[row+j]=false;
            res.pop_back();
        }
    }
    }
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        memset(col,0,sizeof(col));
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        res.clear();
        ret.clear();
        dfs(0);
        return ret;
    }
};
// @lc code=end