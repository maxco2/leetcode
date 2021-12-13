//
// @lc app=leetcode.cn id=179694888 lang=cpp
//
// [179694888] shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof [数组中出现次数超过一半的数字]
//
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int cur=-1;
        for(auto n:nums){
            if(count==0){
                count+=1;
                cur=n;
            }else{
                if(cur==n) count+=1;
                else count-=1;
            }
        }
        return cur;

    }
};
// @lc code=end