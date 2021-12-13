//
// @lc app=leetcode.cn id=189528111 lang=cpp
//
// [189528111] max-points-on-a-line [直线上最多的点数]
//
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res=1;
        for(int i=0;i<points.size();++i){
            map<string,int> mem;
            for(int j=i+1;j<points.size();++j){
                int dx=points[i][0]-points[j][0];
                int dy=points[i][1]-points[j][1];
                int k=gcd(dx,dy);
                string s=to_string(dx/k)+"_"+to_string(dy/k);
                if(mem.count(s)){
                    mem[s]+=1;
                    res=max(res,mem[s]);
                }else{
                    mem.insert({s,2});
                    res=max(2,res);
                }
            }
        }
        return res;
    }
    int gcd(int a,int b){
        if(b) while((a %= b) && (b %= a));
	    return a + b;
    }
};
// @lc code=end