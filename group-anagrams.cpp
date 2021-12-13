//
// @lc app=leetcode.cn id=186531337 lang=cpp
//
// [186531337] group-anagrams [字母异位词分组]
//
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string,int> mem;
        
        for(auto& s:strs){
            if(ret.empty()){
                auto c=s;
                sort(c.begin(),c.end());

                mem.insert({c,ret.size()});
                ret.push_back({s});
            }else{
                auto c=s;
                sort(c.begin(),c.end());
                if(mem.count(c)){
                    ret[mem[c]].push_back(s);
                }else{
                    mem.insert({c,ret.size()});
                    ret.push_back({s});
                }
            }
        }
        return ret;
    }
};
// @lc code=end