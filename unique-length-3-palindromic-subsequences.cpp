//
// @lc app=leetcode.cn id=194439072 lang=cpp
//
// [194439072] unique-length-3-palindromic-subsequences [长度为 3 的不同回文子序列]
//
class Solution {
public:
    using ull=unsigned long long;
    ull one[26];
    ull two[26][26];
    bool cnt[26][26];
    int countPalindromicSubsequence(string s) {
        //unordered_map<string,int> one;
        memset(one,0,sizeof(one));
        memset(two,0,sizeof(two));
        memset(cnt,0,sizeof(cnt));
        for(auto c:s){
            for(int i=0;i<26;++i){
                if(two[c-'a'][i]){
                    cnt[c-'a'][i]=true;
                }
            }
            for(int i=0;i<26;++i){
                two[i][c-'a']+=one[i];
            }
            one[c-'a']++;
        }
        int res=0;
        for(int i=0;i<26;++i){
            for(int j=0;j<26;++j){
                if(cnt[i][j]) res+=1;
            }
        }
        return res;
    }
};
// @lc code=end