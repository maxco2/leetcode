//
// @lc app=leetcode.cn id=189909536 lang=cpp
//
// [189909536] sliding-puzzle [滑动谜题]
//
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string s;
        for(auto & v:board){
            for(auto c:v){
                s+='0'+c;
            }
        }
        unordered_map<string,int> mem;
        queue<string> q;
        string tar="123450";
        q.push(s);
        mem.insert({s,0});
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};
        while(!q.empty()){
            auto cur=q.front();q.pop();
            auto d=mem[cur];
            if(cur==tar) return d;
            auto p=cur.find('0');
            auto x=p/3;
            auto y=p%3;
            for(int i=0;i<4;++i){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0&&nx<2&&ny>=0&&ny<3){
                    swap(cur[p],cur[nx*3+ny]);
                    if(!mem.count(cur)){
                        q.push(cur);
                        mem.insert({cur,d+1});
                    }
                    swap(cur[p],cur[nx*3+ny]);
                }
            }
        }
        return -1;
    }
};
// @lc code=end