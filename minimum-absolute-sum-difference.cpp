//
// @lc app=leetcode.cn id=195566586 lang=cpp
//
// [195566586] minimum-absolute-sum-difference [绝对差值和]
//
constexpr int MOD=1e9+7;
class Solution {
public:
int n;
    int check(vector<int>& nums1,vector<int>& f,int n2){
        int l=0;
        int r=n-1;
        int ans=r;
        while(l<=r){
            int mid=l+r>>1;
            if(nums1[f[mid]]>=n2) ans=mid,r=mid-1;
            else l=mid+1;
        }
        int diff=abs(nums1[f[ans]]-n2);
        //printf("select1:%d ",nums1[f[ans]]);
        l=0;
        r=n-1;
        ans=l;
        while(l<=r){
            int mid=l+r>>1;
            if(nums1[f[mid]]<=n2) ans=mid,l=mid+1;
            else r=mid-1;
        }
        //printf("select2:%d \n",nums1[f[ans]]);
        diff=min(diff,(int)(abs(nums1[f[ans]]-n2)));
        return diff;
    }
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        using ll = long long;
        n=nums1.size();
        vector<int> f(nums1.size(),0);
        for(int i=1;i<nums1.size();++i) f[i]=i;
        sort(f.begin(),f.end(),[&nums1](int a,int b){return nums1[a]<nums1[b];});
        int diff=0;
        ll res=0;
        for(auto i:f){
            int n1=nums1[i];
            int n2=nums2[i];
            int tdiff=abs(n1-n2);
            res=(res+tdiff)%MOD;
            if(tdiff==0) continue;
            int cdiff=check(nums1,f,n2);
            //printf("n1:%d,n2:%d,tdiff:%d,cdiff:%d\n",n1,n2,tdiff,cdiff);
            if(cdiff<tdiff)
            diff=max({diff,tdiff-cdiff});
        }
        res-=diff;
        res%=MOD;
        while(res<0){
            res+=MOD;
        }
        return (res)%MOD;
    }
};
// @lc code=end