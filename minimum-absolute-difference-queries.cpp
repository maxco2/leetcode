//
// @lc app=leetcode.cn id=188506788 lang=cpp
//
// [188506788] minimum-absolute-difference-queries [查询差绝对值的最小值]
//
const int N=100010;
const int M=105;
int pre[N][M];
class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        memset(pre[0],0,sizeof(pre[0]));
        int idx=1;
        for(auto n:nums){
            memcpy(pre[idx],pre[idx-1],sizeof(int)*M);
            pre[idx][n]++;
            idx+=1;
        }
        vector<int> ret;
        for(auto&q:queries){
            auto l=q[0]+1;
            auto r=q[1]+1;
            auto last=-1,res=100;
            for(int i=1;i<=100;++i){
                if(pre[r][i]-pre[l-1][i]){
                    //num exist
                    if(last==-1){
                        last=i;
                    }else{
                        res=min(res,i-last);
                        last=i;
                    }
                }
            }
            if(res!=100) ret.push_back(res);
            else ret.push_back(-1);
        }
        return ret;
    }
};
// @lc code=end