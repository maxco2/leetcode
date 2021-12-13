//
// @lc app=leetcode.cn id=181884667 lang=cpp
//
// [181884667] total-hamming-distance [汉明距离总和]
//
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
int ans = 0, n = nums.size();
        for (int i = 0; i < 30; ++i) {
            int c = 0;
            for (int val : nums) {
                c += (val >> i) & 1;
            }
            ans += c * (n - c);
        }
        return ans;
    }
};
// @lc code=end