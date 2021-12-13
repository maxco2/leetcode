//
// @lc app=leetcode.cn id=190172061 lang=cpp
//
// [190172061] number-of-wonderful-substrings [最美子字符串的数目]
//
class Solution {
public:
    using ll=long long;
    ll cnt[1034];
    long long wonderfulSubstrings(string word) {
        int n=word.size();
        memset(cnt,0,sizeof(cnt));
        cnt[0]++;
        ll res=0;
        auto state = 0;
        for(int i=0;i<n;++i){
            state=state^(1<<(word[i]-'a'));
            res+=cnt[state];
            for(int j=0;j<10;++j){
                res+=cnt[state^(1<<j)];
            }
            cnt[state]++;
        }
        return res;
    }
};
// @lc code=end