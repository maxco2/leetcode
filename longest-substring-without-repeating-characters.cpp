//
// @lc app=leetcode.cn id=195791400 lang=cpp
//
// [195791400] longest-substring-without-repeating-characters [无重复字符的最长子串]
//
class Solution {
public:
    int cnt[256];
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0,r=-1,res=0;
        memset(cnt,0,sizeof(cnt));
        for(;l<n;--cnt[s[l++]]){
            while(r+1<n&&cnt[s[r+1]]+1<2) cnt[s[++r]]++;
            res=max(res,r-l+1);
        }
        return res;
    }
};
// @lc code=end