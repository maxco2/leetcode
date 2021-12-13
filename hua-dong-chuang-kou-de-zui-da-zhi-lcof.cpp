//
// @lc app=leetcode.cn id=203719234 lang=cpp
//
// [203719234] hua-dong-chuang-kou-de-zui-da-zhi-lcof [滑动窗口的最大值]
//
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        vector<int> q(nums.size(),0);
        int hh=0,tt=-1;
        for(int i=0;i<nums.size();++i){
            if(hh<=tt&&q[hh]<=i-k) hh++;
            while(hh<=tt&&nums[q[tt]]<=nums[i]){
                --tt;
            }
            q[++tt]=i;
            if(i>=k-1) ret.push_back(nums[q[hh]]);
        }
        return ret;
    }
};
// @lc code=end