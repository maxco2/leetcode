//
// @lc app=leetcode.cn id=170047064 lang=cpp
//
// [170047064] longest-common-prefix [最长公共前缀]
//
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string& ret=strs[0];
        for(int i=1;i<strs.size();++i){
            auto& s=strs[i];
            int j=0;
            for(;j<min(ret.size(),s.size());++j){
                if(s[j]!=ret[j]){
                    break;
                }
            }
            if(j!=ret.size()){
                while(ret.size()!=j){
                    ret.pop_back();
                }
            }
            if(ret.empty()) return ret;
        }
        return ret;
    }
};
// @lc code=end