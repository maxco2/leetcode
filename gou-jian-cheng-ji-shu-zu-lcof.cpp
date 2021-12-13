//
// @lc app=leetcode.cn id=192786400 lang=cpp
//
// [192786400] gou-jian-cheng-ji-shu-zu-lcof [构建乘积数组]
//
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if(a.empty()) return {};
        vector<int> ret(a.size(),1);
        int tmp=1;
        for(int i=0;i<a.size()-1;++i){
            tmp*=a[i];
            ret[i+1]*=tmp;
        }
        tmp=1;
        for(int i=a.size()-1;i>=1;--i){
            tmp*=a[i];
            ret[i-1]*=tmp;
        }
        return ret;
    }
};
// @lc code=end