//
// @lc app=leetcode.cn id=169860371 lang=cpp
//
// [169860371] he-wei-sde-liang-ge-shu-zi-lcof [和为s的两个数字]
//
class Solution {
public:
    bool bs(vector<int>& nums,int t){
        int l=0;
        int r=nums.size()-1;
        int ans=l;
        while(l<=r){
            int mid=l+r>>1;
            if(nums[mid]>=t) ans=mid,r=mid-1;
            else l=mid+1;
        }
        if(nums[ans]==t){return true;}
        else return false;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        for(int i=0;i<nums.size()&&nums[i]<target;++i){
            if(nums[i]*2==target){
                if(i+1<nums.size()&&nums[i+1]==nums[i]){
                    ret.push_back(nums[i]);
                    ret.push_back(nums[i]);
                    return ret;
                }
            }else{
                if(bs(nums,target-nums[i])){
                    ret.push_back(nums[i]);
                    ret.push_back(target-nums[i]);
                    return ret;
                }
            }
        }
        return ret;
    }
};
// @lc code=end