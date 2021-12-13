//
// @lc app=leetcode.cn id=168789806 lang=cpp
//
// [168789806] reverse-words-in-a-string [翻转字符串里的单词]
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        //reverse all
        std::reverse(s.begin(),s.end());
        auto l=s.size();
        int p=0,q=0,oldp=0;
        int words_len=0;
        int words=0;
        // remove all extra space
        while(p<l){
            // at least one word
            while(p<l&&s[p]==' ') p++;
            q=p;
            while(q<l&& s[q]!=' ') q++;
            reverse(s.begin()+p, s.begin()+q);
            if(oldp!=p)
            copy_n(s.begin()+p, q-p,  s.begin()+oldp);
            words_len+=q-p;
            if(q-p)
                words+=1;
            if(oldp+q-p<l)
                s[oldp+q-p]=' ';
            oldp=oldp+q-p+1;
            p=q+1;
        }
        if(words==1){
            s.resize(words_len);
        } else {
            s.resize(words_len+(words-1));
        }
        return s;
    }
};
// @lc code=end