//
// @lc app=leetcode.cn id=168789855 lang=cpp
//
// [168789855] reverse-string [反转字符串]
//
class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int l=0,r=s.size()-1;l<r;l++,r--){
            auto tmp=s[l];
            s[l]=s[r];
            s[r]=tmp;
        }
    }
};
// @lc code=end