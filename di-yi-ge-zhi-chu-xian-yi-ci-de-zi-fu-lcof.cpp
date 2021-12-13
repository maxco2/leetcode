//
// @lc app=leetcode.cn id=179099606 lang=cpp
//
// [179099606] di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof [第一个只出现一次的字符]
//
class Solution {
public:
    int order[26];
    int c[26];
    char firstUniqChar(string s) {
        if(s.empty()) return ' ';
        int co=0;
        for(auto cc:s){
            int idx=cc-'a';
            if(c[idx]==0){
                c[idx]+=1;
                order[co++]=idx;
            }else{
                c[idx]+=1;
            }
        }
        for(int i=0;i<26;++i){
            if(c[order[i]]==1){
                return 'a'+order[i];
            }
        }
        return ' ';

    }
};
// @lc code=end