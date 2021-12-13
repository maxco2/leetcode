//
// @lc app=leetcode.cn id=205358964 lang=cpp
//
// [205358964] arithmetic-slices [等差数列划分]
//
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        auto d=nums;
        for(int i=1;i<nums.size();++i){
            d[i]=nums[i]-nums[i-1];
        }
        int res=0;
        for(int i=1;i<nums.size();++i){
            int last=d[i];
            //cout<<last<<" i:"<<i<<endl;
            for(int j=i+1;j<nums.size();++j){
                if(d[j]==last){
                    res+=1;
                }else{
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end