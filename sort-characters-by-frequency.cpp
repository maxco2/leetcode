//
// @lc app=leetcode.cn id=192058798 lang=cpp
//
// [192058798] sort-characters-by-frequency [根据字符出现频率排序]
//
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mem;
        for(auto c:s){
            mem[c]++;
        }
        sort(s.begin(),s.end(),[&mem](char a,char b){
            if(mem[a]==mem[b]) return a>b;
            return mem[a]>mem[b];});
        return s;
    }
};
// @lc code=end