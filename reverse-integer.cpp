//
// @lc app=leetcode.cn id=197937979 lang=cpp
//
// [197937979] reverse-integer [整数反转]
//
class Solution {
public:

    int reverse(int x) {
        if(x==INT_MIN) return 0;
        if(x<0) return -reverse(-x);
        int res=0;
        while(x){
            if(res<INT_MIN/10||res>INT_MAX/10){
                return 0;
            }
            auto tmp=x%10;
            x/=10;
            res=res*10+tmp;
        }
        return res;
    }
};
// @lc code=end