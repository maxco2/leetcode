//
// @lc app=leetcode.cn id=168789712 lang=cpp
//
// [168789712] counting-bits [比特位计数]
//
class Solution {
public:
    int lowbit(int x)
    {
        return x&(-x);
    }
    //0
    //1
    //10
    vector<int> countBits(int num) {
        vector<int> res(num+1,0);
        for(int i=1;i<=num;++i)
        {
            int sum=1+res[i-lowbit(i)];
            res[i]=sum;
        }
        return res;
    }
};
// @lc code=end