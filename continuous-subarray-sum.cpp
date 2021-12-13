//
// @lc app=leetcode.cn id=183069427 lang=cpp
//
// [183069427] continuous-subarray-sum [连续的子数组和]
//
// presum[i]-presum[j]=0(mod k) i-j>=2
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int,int> m;
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum=0;
        int idx=0;
        for(auto n:nums){
            sum+=n;
            if(sum%k==0&&idx>0) return true;
            if(m.find(sum%k)!=m.end()&&idx-m[sum%k]>1){
                return true;
            }
            if(m.find(sum%k)==m.end()){
                m.insert({sum%k,idx});
            }
            idx+=1;
        }
        return false;
    }
};
// @lc code=end