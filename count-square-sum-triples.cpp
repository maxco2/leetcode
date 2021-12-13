//
// @lc app=leetcode.cn id=194316110 lang=cpp
//
// [194316110] count-square-sum-triples [统计平方和三元组的数目]
//
class Solution {
public:
    
    int countTriples(int n) {
        vector<int> tmp;
        for(int i=1;i<=n;++i) tmp.push_back(i*i);
        int res=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
            {
                auto it=lower_bound(tmp.begin(),tmp.end(),tmp[i-1]+tmp[j-1]);
                if(it!=tmp.end()&&(*it)==tmp[i-1]+tmp[j-1]){
                    res++;
                }
            }
        return res;
    }
};
// @lc code=end