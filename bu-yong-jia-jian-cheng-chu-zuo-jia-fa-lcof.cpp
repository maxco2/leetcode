//
// @lc app=leetcode.cn id=179689565 lang=cpp
//
// [179689565] bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof [不用加减乘除做加法]
//
class Solution {
public:
    using ui=unsigned int;
    ui addu(ui a,ui b){
        while(b!=0){
            auto c=(a&b)<<1;
            a^=b;
            b=c;
        }
        return a;
    }
    int add(int a, int b) {
        return addu(a,b);
    }
};
// @lc code=end