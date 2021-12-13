//
// @lc app=leetcode.cn id=203747305 lang=cpp
//
// [203747305] ti-huan-kong-ge-lcof [替换空格]
//
class Solution {
public:
    string replaceSpace(string s) {
        string ret;
        for(auto c:s){
            if(c==' '){
                ret+="%20";
            }else{
                ret+=c;
            }
        }
        return ret;
    }
};
// @lc code=end