//
// @lc app=leetcode.cn id=186968447 lang=cpp
//
// [186968447] top-k-frequent-elements [前 K 个高频元素]
//
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mem;
        for(auto n:nums) mem[n]+=1;
        vector<pair<int,int>> s;
        for(auto& p:mem) s.push_back(p);
        sort(s.begin(),s.end(),[](const auto& a,const auto& b){return a.second>b.second;});
        vector<int> ret;
        for(int i=0;i<k;++i) ret.push_back(s[i].first);
        return ret;
    }
};
// @lc code=end