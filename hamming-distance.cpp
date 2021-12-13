//
// @lc app=leetcode.cn id=181475247 lang=cpp
//
// [181475247] hamming-distance [汉明距离]
//
class Solution {
public:
    int hammingDistance(int x, int y) {
        unsigned int z=(x^y);
        int i=0;
        while(z){
            if(z&1) i+=1;
            z>>=1;
        }
        return i;

    }
};
// @lc code=end