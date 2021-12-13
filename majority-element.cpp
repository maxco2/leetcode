//
// @lc app=leetcode.cn id=178746630 lang=cpp
//
// [178746630] majority-element [多数元素]
//
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (int num : nums) {
            if (num == candidate)
                ++count;
            else if (--count < 0) {
                candidate = num;
                count = 1;
            }
        }
        return candidate;

    }
};
// @lc code=end