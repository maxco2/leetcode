//
// @lc app=leetcode.cn id=193242205 lang=cpp
//
// [193242205] count-good-meals [大餐计数]
//
const int MOD=1e9+7;
class Solution {
public:
    // d[i]+d[j]=2^x;
    // 2^20+2^20=2^21;
    // 21*
    using ull=unsigned long long;
    int mi[22];
    int qmi(ull a,int b){
        ull res=1;
        while(b){
            if(b&1) res*=a;
            b>>=1;
            a=a*a;
        }
        return res;
    }
    int countPairs(vector<int>& ds) {
        sort(ds.begin(),ds.end());
        for(int i=0;i<=21;++i){
            mi[i]=qmi(2,i);
        }
        unordered_map<int,int> mem;
        for(auto n:ds) mem[n]+=1;
        ull res=0;
        //cout<<"?"<<endl;
        for(auto& x:mem){
            for(int i=0;i<=21;i++){
                auto others=mi[i]-x.first;
                if(others==x.first&&x.second!=1){
                    //C(x.second,2)
                    res+=((ull)x.second*(x.second-1))/2;
                    res%=MOD;
                }else if(others<x.first&&mem.count(others)){
                    res+=((ull)(mem[others])*x.second)%MOD;
                    res%=MOD;
                }
            }
        }
        return res;
    }
};
// @lc code=end