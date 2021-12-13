//
// @lc app=leetcode.cn id=176932536 lang=cpp
//
// [176932536] valid-sudoku [有效的数独]
//
class Solution {
public:
    bool mem[9];
    bool isValidSudoku(vector<vector<char>>& b) {
        for(int i=0;i<9;++i){
            memset(mem,0,sizeof(mem));
            for(int j=0;j<9;++j){
                if(b[i][j]!='.'){
                    int tmp=b[i][j]-'1';
                    if(mem[tmp]){
                        return false;
                    }else{
                        mem[tmp]=true;
                    }
                }
            }
            memset(mem,0,sizeof(mem));
            for(int j=0;j<9;++j){
                if(b[j][i]!='.'){
                    int tmp=(b[j][i]-'1');
                    if(mem[tmp]){
                        return false;
                    }else{
                        mem[tmp]=true;
                    }
                }
            }
        }
        int dx[3]={0,3,6};
        int dy[3]={0,3,6};
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                int stx=dx[i];
                int sty=dx[j];
                memset(mem,0,sizeof(mem));
                for(int m=stx;m<stx+3;++m){
                    for(int n=sty;n<sty+3;++n){
                    if(b[m][n]!='.'){
                    int tmp=b[m][n]-'1';
                    if(mem[tmp]){
                        return false;
                    }else{
                        mem[tmp]=true;
                    }
                    }
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end