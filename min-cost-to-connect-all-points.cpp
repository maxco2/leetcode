//
// @lc app=leetcode.cn id=196386441 lang=cpp
//
// [196386441] min-cost-to-connect-all-points [连接所有点的最小费用]
//
class Solution {
public:
    struct Edge{
        int p1,p2;
        int d;
        Edge(){}
        Edge(const vector<int>& p1,const vector<int>& p2,int i,int j){
            int x1=p1[0],y1=p1[1],x2=p2[0],y2=p2[1];
            this->p1=i,this->p2=j;
            d=abs(x1-x2)+abs(y1-y2);
        }
        bool operator<(const Edge& that) const{
            return d<that.d;
        }
    };
    int find(int x){
        if(p[x]!=x){
            p[x]=find(p[x]);
        }
        return p[x];
    }

    vector<int> p;
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<Edge> edges;
        int n=points.size();
        if(n==1) return 0;
        p=vector<int>(points.size(),0);
        for(int i=0;i<n;++i){
            p[i]=i;
            for(int j=i+1;j<n;++j){
                Edge e(points[i],points[j],i,j);
                edges.push_back(e);
            }
        }
        sort(edges.begin(),edges.end());
        int res=0;
        for(auto&e:edges){
            int pa=find(e.p1);
            int pb=find(e.p2);
            if(pa!=pb){
                p[pa]=pb;
                res+=e.d;
            }
            //cout<<e.p1<<endl;
            //cout<<e.p2<<endl;
            //cout<<e.d<<endl;
        }
        return res;
    }
};
// @lc code=end