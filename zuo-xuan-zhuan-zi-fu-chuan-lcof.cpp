//
// @lc app=leetcode.cn id=179669083 lang=cpp
//
// [179669083] zuo-xuan-zhuan-zi-fu-chuan-lcof [左旋转字符串]
//
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(),s.end());
        reverse(s.begin(),s.end()-n);
        reverse(s.end()-n,s.end());
        return s;

    }
};
// @lc code=end