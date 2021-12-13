//
// @lc app=leetcode.cn id=171996423 lang=cpp
//
// [171996423] capacity-to-ship-packages-within-d-days [在 D 天内送达包裹的能力]
//
class Solution {
public:
    //s1+s2+..+sd=sum
    //min(s_i)
    // weight k
    bool check(vector<int>& weights,int D,int v){
        int vv=v;
        for(auto n:weights){
            if(D==0) return false;
            if(v-n>=0)
                v-=n;
            else
            {
                v=vv;
                v-=n;
                D-=1;
            }
        }
        D-=1;
        if(D<0) return false;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int l=1;
        int sum=0;for(auto n:weights) sum+=n,l=max(l,n);
        if(D==1) return sum;
        int r=sum;
        int ans=r;
        while(l<=r){
            int mid=l+r>>1;
            if(check(weights,D,mid)) ans=mid,r=mid-1;
            else l=mid+1;
        }
        return ans;
    }
};
// @lc code=end