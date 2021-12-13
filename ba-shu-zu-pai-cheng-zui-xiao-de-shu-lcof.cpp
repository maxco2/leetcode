//
// @lc app=leetcode.cn id=177806801 lang=cpp
//
// [177806801] ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof [把数组排成最小的数]
//
class Solution {
public:
    vector<string> snums;
    string minNumber(vector<int>& nums) {
        auto sz=nums.size();
        for(auto n:nums) snums.emplace_back(to_string(n));
        if(sz==1) return snums[0];
        sort(snums.begin(),snums.end(),[](const string& a,const string& b){
            return a+b<b+a;
        });
        string ret;
        for(auto& s:snums) ret+=s;
        return ret;
    }
};
// @lc code=end