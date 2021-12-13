//
// @lc app=leetcode.cn id=179814983 lang=cpp
//
// [179814983] top-k-frequent-words [前K个高频单词]
//
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        vector<string> ret;
        for(auto& w:words){
            if(!m.count(w)) ret.push_back(w);
            m[w]+=1;
        }
        sort(ret.begin(),ret.end(),[&m](const string& a,const string& b){
            if(m[a]==m[b]){
                return a<b;
            }
            return m[a]>m[b];
        });
        while(ret.size()!=k) ret.pop_back();
        return ret;
    }
};
// @lc code=end