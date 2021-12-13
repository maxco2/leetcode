//
// @lc app=leetcode.cn id=201305597 lang=cpp
//
// [201305597] excel-sheet-column-number [Excel 表列序号]
//
class Solution {
public:
    int qsi(long a,int b){
        long  res=1;
        while(b){
            if(b&1) res*=a;
            b>>=1;
            a=a*a;
        }
        return res;
    }
    int titleToNumber(string columnTitle) {
        int res=0;
        int q=0;
        for(auto it=columnTitle.rbegin();it!=columnTitle.rend();++it){
            res+=qsi(26,q++)*(*it-'A'+1);
        }
        return res;
    }
};
// @lc code=end