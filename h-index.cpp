//
// @lc app=leetcode.cn id=194455533 lang=cpp
//
// [194455533] h-index [H 指数]
//
class Solution {
public:
    bool check(int mid,vector<int>& citations){
        int p1=0;
        int p2=0;
        for(auto n:citations){
            if(n>=mid){
                p1+=1;
            }else{
                p2+=1;
            }
        }
        if(p1>=mid) return true;
        return false;
    }
    int hIndex(vector<int>& citations) {
        int r=citations.size();
        int l=0;
        int ans=l;
        while(l<=r){
            int mid=l+r>>1;
            if(check(mid,citations)) ans=mid,l=mid+1;
            else r=mid-1;
        }
        return ans;
    }
};
// @lc code=end