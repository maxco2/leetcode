//
// @lc app=leetcode.cn id=177955992 lang=cpp
//
// [177955992] daily-temperatures [每日温度]
//
class Solution {
public:
    int s[30000];
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> ret(t.size(),0);
        int top=0;
        int idx=0;
        for(auto n:t){
            while(top>0&&t[s[top-1]]<n){
                ret[s[top-1]]=idx-s[top-1];
                top--;
            }
            s[top++]=idx++;
        }
        return ret;

    }
};
// @lc code=end