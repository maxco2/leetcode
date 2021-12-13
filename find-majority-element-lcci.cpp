//
// @lc app=leetcode.cn id=193766540 lang=cpp
//
// [193766540] find-majority-element-lcci [主要元素]
//
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int cur=-1;
        for(auto n:nums){
            if(cnt==0){
                cur=n;
            }
            if(cur==n){
                cnt++;
            }else{
                cnt--;
            }
        }
        cnt=0;
        //cout<<cur<<endl;
        for(auto x:nums){
            if(x==cur){
                cnt++;
            }
        }
        return cnt*2>nums.size()?cur:-1;
    }
};
// @lc code=end