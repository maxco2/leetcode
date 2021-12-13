//
// @lc app=leetcode.cn id=192058849 lang=cpp
//
// [192058849] set-mismatch [错误的集合]
//
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int last=-1;
        vector<int> res;
        int tmp=0;
        for(auto i=1;i<=nums.size();++i) tmp^=i;
        for(int i=0;i<nums.size();++i){
            tmp^=nums[i];
            if(nums[i]==last){
                res.push_back(last);
                tmp^=nums[i];
            }else{
                last=nums[i];
            }
        }
        res.push_back(tmp);
        return res;
    }
};
// @lc code=end