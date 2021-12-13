//
// @lc app=leetcode.cn id=188130512 lang=cpp
//
// [188130512] largest-odd-number-in-string [字符串中的最大奇数]
//
class Solution {
public:
    string largestOddNumber(string num) {

        int pos=-1;
        for(int i=num.size()-1;i>=0;i--){
            if((num[i]-'0')%2==1){
                pos=i+1;
                break;
            }
        }
        if(pos!=-1)
        {
            num.resize(pos);
            return num;
        }
            return "";

    }
};
// @lc code=end