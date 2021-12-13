//
// @lc app=leetcode.cn id=189994014 lang=cpp
//
// [189994014] remove-all-occurrences-of-a-substring [删除一个字符串中所有出现的给定子字符串]
//
class Solution {
public:
     string removeOccurrences1(string& s, string& part){
            if(s.size()<part.size()) return s;
            auto pos=s.find(part);
            if(pos==string::npos){
                return s;
            }
            
            while(pos!=string::npos){
                s=s.replace(pos,part.size(),"");
                pos=s.find(part);
            }
            return s;
    }
    string removeOccurrences(string s, string part) {
           return removeOccurrences1(s,part);
    }
};
// @lc code=end