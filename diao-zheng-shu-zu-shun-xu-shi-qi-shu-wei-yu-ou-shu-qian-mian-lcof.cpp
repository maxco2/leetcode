//
// @lc app=leetcode.cn id=179096026 lang=cpp
//
// [179096026] diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof [调整数组顺序使奇数位于偶数前面]
//
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if(nums.empty()) return {};
        int l=-1;
        int r=nums.size();
    
        while(l<r){
            do l++; while(l<nums.size()&&nums[l]%2==1);
            do r--; while(r>=0&&nums[r]%2==0);
            if(l<r)
                swap(nums[l],nums[r]);
        }

        return nums;

    }
};
// @lc code=end