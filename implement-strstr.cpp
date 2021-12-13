//
// @lc app=leetcode.cn id=178770421 lang=cpp
//
// [178770421] implement-strstr [实现 strStr()]
//
constexpr int p=37;
class Solution {
public:
    using u32=uint32_t;
    u32 prk=2;

    pair<u32,u32> calc(string& n,int sz){
        u32 h=0;
        u32 sq=1;
        for (int i = 0; i < sz; i ++ ){
            h=h*prk+u32(n[i]);
            if(i!=sz-1) sq*=prk;
        }
        return {h,sq};
    }

    int strStr(string s, string n) {
        int nsz=n.size();
        int ssz=s.size();
        auto hh1=calc(n,nsz);
        auto h=hh1.first;
        auto sq=hh1.second;
        auto fh=calc(s,nsz).first;
        if(h==fh&&memcmp(n.c_str(),s.c_str(),nsz)==0) return 0;
        for(int i=1;i<=ssz-nsz;++i){
            fh-=s[i-1]*sq;
            fh=fh*prk+s[i+nsz-1];
            if(h==fh) return i;
        }
        return -1;
    }
};
// @lc code=end