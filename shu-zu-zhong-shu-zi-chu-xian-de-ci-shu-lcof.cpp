//
// @lc app=leetcode.cn id=180516471 lang=cpp
//
// [180516471] shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof [数组中数字出现的次数]
//
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int r=0;
        for(auto n:nums) r^=n;
        int bb=1;
        while((bb&r)==0)
        bb<<=1;
        int a=0;int b=0;
        for(auto n:nums){
            if(bb&n){
                a^=n;
            }else{
                b^=n;
            }
        }
        vector<int> ret;
        ret.push_back(a);
        ret.push_back(b);
        return ret;
    }
};
// @lc code=end