//
// @lc app=leetcode.cn id=190690101 lang=cpp
//
// [190690101] sliding-window-maximum [滑动窗口最大值]
//
const int N = 1e5+10;
class Solution {
public:

    int st[N];
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        int hh=0,tt=-1;
        for(int i=0;i<nums.size();++i){
            if(hh<=tt&&st[hh]<=i-k) hh++;
            while(hh<=tt&&nums[st[tt]]<=nums[i]){
                tt--;
            }
            st[++tt]=i;
            if(i>=k-1) ret.push_back(nums[st[hh]]);
        }
        return ret;
    }
};
// @lc code=end