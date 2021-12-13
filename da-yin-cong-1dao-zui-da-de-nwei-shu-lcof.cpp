//
// @lc app=leetcode.cn id=169685048 lang=cpp
//
// [169685048] da-yin-cong-1dao-zui-da-de-nwei-shu-lcof [打印从1到最大的n位数]
//
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> ret;
        int p=pow(10,n);
        for(int i=1;i<p;++i){
            ret.push_back(i);
        }
        return ret;
    }
};
// @lc code=end