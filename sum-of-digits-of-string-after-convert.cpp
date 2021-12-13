//
// @lc app=leetcode.cn id=199500798 lang=cpp
//
// [199500798] sum-of-digits-of-string-after-convert [字符串转化后的各位数字之和]
//
class Solution {
public:
    using ull=unsigned long long;
    
    ull add(ull a){
       ull res=0;
        while(a){
            res+=(a%10);
            a/=10;
        }
        return res;
    }
    int getLucky(string s, int k) {
        vector<int> r1;
        vector<int> r2;
        ull ret=0;
        for(auto c:s){
            ret+=add(c-'a'+1);
        }
        k-=1;
        while(k){
            ull tmp=0;
            tmp+=add(ret);
            ret=tmp;
            k--;
        }
        
        return ret;
    }
};
// @lc code=end