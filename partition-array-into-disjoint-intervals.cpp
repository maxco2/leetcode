//
// @lc app=leetcode.cn id=177223198 lang=cpp
//
// [177223198] partition-array-into-disjoint-intervals [分割数组]
//
class Solution {
public:
    bool check(vector<int>& nums,int m){
        //cout<<"check"<<m;
        return lmaxv[m-1]<=rminv[nums.size()-m-1];
    }

    vector<int> lmaxv;
    vector<int> rminv;

    int partitionDisjoint(vector<int>& nums) {
        int lmax=-1;
        lmaxv.clear();
        rminv.clear();
        for(auto n:nums){
            lmax=max(n,lmax);
            lmaxv.push_back(lmax);
        }
        int rmin=(int)1e7;
        for(int i=nums.size()-1;i>=0;--i){
            rmin=min(rmin,nums[i]);
            rminv.push_back(rmin);
        }
        int ans=31000;
        for(int i=1;i<=nums.size()-1;++i){
            if(check(nums,i)){
                ans=min(ans,i);
            }
        }
        return ans;
    }
};
// @lc code=end