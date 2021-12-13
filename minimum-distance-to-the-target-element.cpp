//
// @lc app=leetcode.cn id=186057072 lang=cpp
//
// [186057072] minimum-distance-to-the-target-element [到目标元素的最小距离]
//
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int idx=0;
        int ret=-1;
        for(auto n:nums){
            if(n==target){
                if(ret==-1){
                    ret=abs(idx-start);
                }else if(abs(idx-start)<=ret){
                    ret=abs(idx-start);
                }else{
                    return ret;
                }
            }
            idx+=1;
        }
        return ret;
    }
};
// @lc code=end