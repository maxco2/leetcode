//
// @lc app=leetcode.cn id=190398652 lang=cpp
//
// [190398652] bus-routes [公交路线]
//
class Solution {
public:
    static const int N=1e6;
    bool st[510];
    int dist[510];
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        vector<vector<int>> g(510,vector<int>(510,0x3f3f3f3f));
        auto mark=1;
        unordered_map<int,vector<int>> mem; // no->i (where i is routes[i])
        for(int i=0;i<routes.size();++i){
            auto& v=routes[i];
            unordered_set<int> s;
            for(int j=0;j<v.size();++j){
                s.insert(v[j]);
                if(mem.count(v[j])){
                    auto &ast=mem[v[j]];
                    for(int k=0;k<ast.size();++k)
                    g[i+1][ast[k]]=g[ast[k]][i+1]=1;
                    ast.push_back(i+1);
                }else{
                    mem.insert({v[j],{i+1}});
                }
            }
            if(s.count(source)&&s.count(target)) return 1;//souce and target in the same route
        }
        memset(st,0,sizeof st);
        
        queue<pair<int,int>> q;
        for(auto n:mem[source]){
            q.push({n,1});
            st[n]=true;
        }
        unordered_set<int> ts;
        for(auto n :mem[target]){
            ts.insert(n);
        }
        //cout<<"source size"<<mem[source].size()<<endl;
        //cout<<"ts size"<<ts.size()<<endl;
        while(!q.empty()){
            auto t=q.front().first;auto d=q.front().second;q.pop();
            st[t]=true;
            if(ts.count(t)) return d;
            for(int i=1;i<=routes.size();++i){
                if(!st[i]&&g[t][i]==1){
                    q.push({i,d+1});
                    //printf("from %d to %d, dist:%d\n",)
                    st[i]=true;
                }
            }
        }
        return -1;

    }
};
// @lc code=end