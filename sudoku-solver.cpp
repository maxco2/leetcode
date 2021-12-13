//
// @lc app=leetcode.cn id=211557821 lang=cpp
//
// [211557821] sudoku-solver [解数独]
//
class Solution {
public:
    bool dfs(vector<vector<char>>& bd,int remain,int i=0,int j=0){
        if(remain==0){
            return true;
        }
        if(j==9) j=0,i+=1;
        if(i==9){
            return false;
        }
        if(bd[i][j]=='.'){
            int box_num=(i/3)*3+(j/3)*1;
            for(int k=0;k<9;++k){
                if(!box[box_num][k]&&!row[i][k]&&!col[j][k]){
                    bd[i][j]='1'+k;
                    box[box_num][k]=row[i][k]=col[j][k]=true;
                    if(dfs(bd,remain-1,i,j+1)){
                        return true;
                    }
                    bd[i][j]='.';
                    box[box_num][k]=row[i][k]=col[j][k]=false;
                }
            }
        }else{
            if(dfs(bd,remain,i,j+1)){
                return true;
            }
        }
        return false;
    }
    int total;
    bool box[9][9];
    bool row[9][9];
    bool col[9][9];
    void solveSudoku(vector<vector<char>>& bd) {
        memset(box,0,sizeof(box));
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        total=81;
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(bd[i][j]!='.'){
                    int box_num=(i/3)*3+(j/3)*1;
                    int tmp=bd[i][j]-'1';
                    box[box_num][tmp]=true;
                    row[i][tmp]=true;
                    col[j][tmp]=true;
                    total-=1;
                }
            }
        }
        dfs(bd,total);
    }
};
// @lc code=end