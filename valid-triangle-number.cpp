//
// @lc app=leetcode.cn id=203052802 lang=cpp
//
// [203052802] valid-triangle-number [有效三角形的个数]
//
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        nums.push_back(5001);
        int res=0;
        for(int i=0;i<nums.size()-1;++i){
            for(int j=i+1;j<nums.size()-1;++j){
                int l=j+1;
                int r=nums.size()-1;
                int ans=r;
                while(l<=r){
                    int mid=l+r>>1;
                    if(nums[mid]>=nums[i]+nums[j]) ans=mid,r=mid-1;
                    else l=mid+1;
                }
                if(nums[ans]>=nums[i]+nums[j]){
                    res+=(ans-j-1);
                    //for(int k=j+1;k<ans;++k)
                    //printf("%d %d %d\n",nums[i],nums[j],nums[k]);
                }
            }
        }
        return res;
    }
};
// @lc code=end