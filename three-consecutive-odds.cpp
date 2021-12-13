//
// @lc app=leetcode.cn id=170219441 lang=cpp
//
// [170219441] three-consecutive-odds [存在连续三个奇数的数组]
//
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i <= n - 3; ++i) {
            if ((arr[i] & 1) & (arr[i + 1] & 1) & (arr[i + 2] & 1)) {
                return true;
            }
        }
        return false;
    }
};

// @lc code=end