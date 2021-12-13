//
// @lc app=leetcode.cn id=172669239 lang=cpp
//
// [172669239] magnetic-force-between-two-balls [两球之间的磁力]
//
class Solution {
public:
    bool check(vector<int>& position,int f,int m){
        int cur=position[0];
        int rem=m-1;
        int l=1;
        while(rem>0&&l<position.size()){
            int r=position.size()-1;
            int ans=r;
            while(l<=r){
                int mid=l+r>>1;
                if(position[mid]>=cur+f) ans=mid,r=mid-1;
                else l=mid+1;
            }
            if(position[ans]>=cur+f){
                cur=position[ans];
                l=ans+1;
                rem-=1;
            }else{
                return false;
            }
        }
        if(rem!=0) return false;
        //printf("force:%d,suc\n",f);
        return true;
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        if(n<m) return 0;
        sort(position.begin(),position.end());
        int l=1;
        int r=position[n-1]-position[0];
        int ans=r;
        while(l<=r){
            int mid=l+r>>1;
            if(check(position,mid,m)) ans=mid,l=mid+1;
            else r=mid-1;
        }
        return ans;
    }
};
// @lc code=end