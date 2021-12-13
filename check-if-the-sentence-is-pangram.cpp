//
// @lc app=leetcode.cn id=169292022 lang=cpp
//
// [169292022] check-if-the-sentence-is-pangram [判断句子是否为全字母句]
//
bool e[26];
class Solution {
public:
    bool checkIfPangram(string sentence) {
        memset(e,0,sizeof(e));
        for(auto c:sentence){
            e[c-'a']=true;
        }
        for(auto ee:e){
            if(!ee) return false;
        }
        return true;
    }
};
// @lc code=end