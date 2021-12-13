//
// @lc app=leetcode.cn id=194616942 lang=cpp
//
// [194616942] find-all-anagrams-in-a-string [找到字符串中所有字母异位词]
//
class Solution {
public:
int mem[26];
int mem2[26];
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        if(s.size()<p.size()) return {};
        memset(mem,0,sizeof(mem));
        memset(mem2,0,sizeof(mem));
        for(auto c:p){
            mem[c-'a']++;
        }
        for(int i=0;i<p.size();++i){
            mem2[s[i]-'a']++;
        }
        if(memcmp(mem2,mem,sizeof(mem))==0){
            ret.push_back(0);
        }
        for(int i=p.size();i<s.size();++i){
            mem2[s[i]-'a']++;
            mem2[s[i-p.size()]-'a']--;
            if(memcmp(mem2,mem,sizeof(mem))==0){
                ret.push_back(i+1-p.size());
            }
        }
        return ret;
    }
};
// @lc code=end