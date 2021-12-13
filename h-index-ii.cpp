//
// @lc app=leetcode.cn id=194674819 lang=cpp
//
// [194674819] h-index-ii [H 指数 II]
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