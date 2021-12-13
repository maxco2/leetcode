//
// @lc app=leetcode.cn id=201502923 lang=cpp
//
// [201502923] base-7 [七进制数]
//
class Solution {
public:
    string convertToBase7(int num) {
        if(num==0) return "0";
        if(num<0){
            string r="-";
            return r+convertToBase7(-num);
        }
        string res;
        while(num){
            auto tmp='0'+num%7;
            res+=tmp;
            num/=7;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end