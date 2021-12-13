//
// @lc app=leetcode.cn id=188155513 lang=cpp
//
// [188155513] the-number-of-full-rounds-you-have-played [你完成的完整对局数]
//
class Solution {
public:
    void gethm(string& s,int &h,int &m){
        h=m=0;
        for(int i=0;i<2;++i)
            h=h*10+(s[i]-'0');
        for(int i=3;i<5;++i){
            m=m*10+(s[i]-'0');
        }
    }
    int numberOfRounds(string sT, string fT) {
        int sth,stm,edh,edm;
        gethm(sT,sth,stm);
        gethm(fT,edh,edm);
        int ret=0;
        if(sth!=edh||(sth==edh&&stm>edm)){
            int d1=4-((stm+14)/15);
            ret+=d1;
            sth+=1;
            int a=edh>=sth?0:24;
            ret+=((edh+a-sth)*4);
            return ret+edm/15;
        }else{
            int d1=(stm+14)/15;
            int d2=(edm/15);
            ret+=(d2-d1);
            return ret;
        }
    }
};
// @lc code=end