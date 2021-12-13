//
// @lc app=leetcode.cn id=215620663 lang=cpp
//
// [215620663] implement-rand10-using-rand7 [用 Rand7() 实现 Rand10()]
//
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int r,c,idx;
        do{
            r=rand7();
            c=rand7();
            idx=(r-1)*7+c;
        }while(idx>40);
        return idx%10+1;
    }
};
// @lc code=end