//
// @lc app=leetcode.cn id=197709400 lang=cpp
//
// [197709400] group-anagrams-lcci [变位词组]
//
class Solution {
public:
    struct Word{
        int cnt[26];
        Word(){
            memset(cnt,0,sizeof(cnt));
        }
        Word(string& s){
            memset(cnt,0,sizeof(cnt));
            for(auto c:s)
            cnt[c-'a']++;
        }
        bool operator<(const Word& that)const{
            for(int i=0;i<26;++i){
                if(cnt[i]<that.cnt[i]){
                    return true;
                }else if(cnt[i]>that.cnt[i]){
                    return false;
                }
            }
            return false;
        }
    };
    map<Word,int> mem;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        for(auto& s:strs){
            Word w(s);
            auto it=mem.find(w);
            if(it!=mem.end()){
                ret[it->second].push_back(s);
            }else{
                mem[w]=ret.size();
                ret.emplace_back(vector<string>{s});
            }
        }
        return ret;
    }
};
// @lc code=end