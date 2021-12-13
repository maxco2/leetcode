//
// @lc app=leetcode.cn id=202758668 lang=cpp
//
// [202758668] shortest-unsorted-continuous-subarray [最短无序连续子数组]
//
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        auto n1=nums;
        sort(n1.begin(),n1.end());
        auto st=-1,ed=-1;
        for(int i=0;i<nums.size();++i)
            if(nums[i]!=n1[i])
            if(st==-1) st=i;else ed=max(ed,i);
        return st==-1?0:ed-st+1;
    }
};
// @lc code=end