//
// @lc app=leetcode.cn id=186250457 lang=cpp
//
// [186250457] redistribute-characters-to-make-all-strings-equal [重新分配字符使所有字符串都相等]
//
class Solution {
public:
    int x[26];
    bool makeEqual(vector<string>& w) {
        memset(x,0,sizeof(x));
        for(auto& s:w){
            for(auto c:s){
                x[c-'a']+=1;
            }
        }
        for(auto t:x){
            if(t%w.size()!=0){
                return false;
            }
        }
        return true;

    }
};
// @lc code=end