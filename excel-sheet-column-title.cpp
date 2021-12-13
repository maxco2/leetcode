//
// @lc app=leetcode.cn id=190879151 lang=cpp
//
// [190879151] excel-sheet-column-title [Excel表列名称]
//
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ret;
        while (columnNumber > 0) {
            columnNumber--;
            ret+=columnNumber % 26 + 'A';
            columnNumber /= 26;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
// @lc code=end