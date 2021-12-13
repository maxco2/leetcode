//
// @lc app=leetcode.cn id=203746828 lang=cpp
//
// [203746828] ju-zhen-zhong-de-lu-jing-lcof [矩阵中的路径]
//
class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    bool st[210][210];
    bool dfs(string& word,vector<vector<char>>& b,int cur,int x,int y){
        if(cur==word.size()) return true;
        st[x][y]=true;
        if(word[cur]==b[x][y]){
            if(cur+1==word.size()) return true;
            for(int i=0;i<4;++i){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0&&nx<m&&ny>=0&&ny<n&&!st[nx][ny]){
                    if(dfs(word,b,cur+1,nx,ny)){
                        return true;
                    }
                    st[nx][ny]=false;
                }
            }
        }
        return false;
    }
    int m,n;
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();memset(st,0,sizeof st);
        for(int i=0;i<m;++i)
        for(int j=0;j<n;++j){
            if(word[0]==board[i][j]){
                if(dfs(word,board,0,i,j)){
                    return true;
                }
                st[i][j]=false;
            }
        }
        return false;
    }
};
// @lc code=end