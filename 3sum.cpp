//
// @lc app=leetcode.cn id=176917808 lang=cpp
//
// [176917808] 3sum [三数之和]
//
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> t{1,2,3};
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3) return {};
        ret.clear();
        sort(nums.begin(),nums.end());
        int iv=nums[0]-1;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==iv){
                continue;
            }else{
                iv=nums[i];
            }
            int j=i+1;
            int k=nums.size()-1;
            int seen=10000000;
            while(j<k){
                int tmp=nums[i]+nums[j]+nums[k];
                if(tmp<0){
                    j++;
                }else if(tmp>0){
                    k--;
                }else{
                    if(nums[j]==seen){
                        j++;continue;
                    }else{
                        seen=nums[j];
                    }
                    t[0]=(nums[i]);
                    t[1]=(nums[j]);
                    t[2]=(nums[k]);
                    ret.push_back(t);
                    j++;
                }
            }
        }
        return ret;
    }
};
// @lc code=end