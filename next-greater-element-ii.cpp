//
// @lc app=leetcode.cn id=177585435 lang=cpp
//
// [177585435] next-greater-element-ii [下一个更大元素 II]
//
class Solution {
public:
    int s[20005];
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ret(nums.size(),-1);
        int top=0;
        int idx=0;
        for(auto n:nums){
            while(top>0&&nums[s[top-1]]<n) {
                ret[s[top-1]]=n;
                top--;
            }
            s[top++]=idx;
            idx+=1;
        }
        idx=0;
        for(auto n:nums){
            while(top>0&&nums[s[top-1]]<n) {
                ret[s[top-1]]=n;
                top--;
            }
            s[top++]=idx;
            idx+=1;
        }
        return ret;
    }
};
// @lc code=end