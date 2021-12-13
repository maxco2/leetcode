//
// @lc app=leetcode.cn id=199535408 lang=cpp
//
// [199535408] largest-number-after-mutating-substring [子字符串突变后可能得到的最大整数]
//
class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool c= false;
        for(int i=0;i<num.size();++i){
            int cur=num[i]-'0';    
            if(cur<change[cur]|| (c&&cur==change[cur])){
                num[i]='0'+change[cur];
                c=true;
            }else if(c){
                break;
            }
        }
        return num;

    }
};
// @lc code=end