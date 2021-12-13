//
// @lc app=leetcode.cn id=176912928 lang=cpp
//
// [176912928] 3sum-closest [最接近的三数之和]
//
class Solution {
public: 
    //a+b+c=target
    //target-c
    int target;
    int check(int re,vector<int>& nums,int j,int i){
        int l=0;
        int r=nums.size()-1;
        int ans=r;
        while(l<=r){
            int mid=l+r>>1;
            if(nums[mid]>=re) ans=mid,r=mid-1;
            else l=mid+1;
        }
        int ret1=100000;int ret2=100000;
        if(ans>max(i,j)){
            ret1=nums[i]+nums[j]+nums[ans];
        }

        l=0;
        r=nums.size()-1;
        ans=l;
        re=nums[i]+nums[j]-target;
        while(l<=r){
            int mid=l+r>>1;
            if(nums[mid]>=re) ans=mid,r=mid-1;
            else l=mid+1;
        }
        if(ans>max(i,j)){
            ret2=nums[i]+nums[j]+nums[ans];
        }
        if(abs(ret1-target)<abs(ret2-target)){
            return ret1;
        }else{
            return ret2;
        }
        
    }
    int threeSumClosest(vector<int>& nums, int _target) {
        target=_target;
        int ret=100000;
        sort(nums.begin(),nums.end());
        for(auto i=0;i<nums.size();++i){
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int tmp=nums[i]+nums[j]+nums[k];
                if(abs(tmp-target)<abs(ret-target)){
                    ret=tmp;
                }
                if(tmp<target){
                    j++;
                }else if(tmp>target){
                    k--;
                }else{
                    return target;
                }
            }
        }
        return ret;

    }
};
// @lc code=end