//
// @lc app=leetcode.cn id=175290105 lang=cpp
//
// [175290105] brick-wall [砖墙]
//
class Solution {
public:
    int ret;
    int m;
    bool isBreak(vector<int>& w,int c){
        int l=0;
        int r=w.size()-1;
        int ans=r;
        while(l<=r){
            int mid=l+r>>1;
            if(w[mid]>=c) ans=mid,r=mid-1;
            else l=mid+1;
        }
        if(w[ans]==c) return true;
        return false;
    }
    bool check(int mid,vector<vector<int>>& wall){
        int b=0;
        for(auto&w:wall){
            if(!isBreak(w,mid)) b+=1;
        }
        //printf("%d:%d\n",mid,b);
        if(b<ret){
            ret=b;
            return true;
        }{
            return false;
        }
    }
    unordered_map<int,int> mem;
    int leastBricks(vector<vector<int>>& wall) {
        m=wall.size();
        ret=m;
        int n=0;
        for(auto l:wall[0]) n+=l;
        int mb=0;
        for(int i=0;i<m;++i){
            int sum=0;
            for(auto& v:wall[i]){
                sum+=v;
                mem[sum]+=1;
                if(sum!=n)
                mb=max(mb,mem[sum]);
                v=sum;
            }
        }
        return ret-mb;
    }
};
// @lc code=end