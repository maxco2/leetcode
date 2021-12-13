//
// @lc app=leetcode.cn id=186797910 lang=cpp
//
// [186797910] word-search [单词搜索]
//
class Solution {
public:
    struct Tp{
        int x;
        int y;
        int p;
        Tp(){}
        Tp(int x,int y,int p):x(x),y(y),p(p){
            memset(vst,0,sizeof vst);
            vst[x][y]=true;
        }
        void copy(Tp& that){memcpy(this->vst,that.vst,sizeof(vst));}
        void set(int x,int y){vst[x][y]=true;}
        bool vst[10][10];
    };
    bool exist(vector<vector<char>>& board, string word) {
        
        int m=board.size();
        int n=board[0].size();
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(word[0]==board[i][j]){
                    int sz=0;
                    queue<Tp> q;
                    q.push({i,j,0});
                    while(!q.empty()){
                        auto cur=q.front();
                        q.pop();
                        auto x=cur.x;
                        auto y=cur.y;
                        auto p=cur.p;
                        auto vst=cur.vst;
                        if(p+1==word.size()){
                            return true;
                        }
                        for(int k=0;k<4;++k){
                            int nx=x+dx[k],ny=y+dy[k];
                            if(nx>=0&&nx<m&&ny>=0&&ny<n&&!vst[nx][ny]&&word[p+1]==board[nx][ny]){
                                auto c=Tp{nx,ny,p+1};
                                c.copy(cur);
                                c.set(nx,ny);
                                q.push(c);
                                //printf("board[%d][%d]=%c\n",nx,ny,board[nx][ny]);
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end