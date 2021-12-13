//
// @lc app=leetcode.cn id=176615050 lang=cpp
//
// [176615050] decode-xored-permutation [解码异或后的排列]
//
class Solution {
public:
    //i i+1 
    //i+1 i+2
    //i+2 i+3
    //i+3 I+4
    
    vector<int> decode(vector<int>& encoded) {
        vector<int> ret;
        int n=encoded.size()+1;
        int all=1;
        for(int i=2;i<=n;++i){
            all^=i;
        }
        int left=encoded[1];
        for(int i=3;i<encoded.size();i+=2){
            left^=encoded[i];
        }
        int first=all^left;
        ret.push_back(first);
        int cur=first^encoded[0];
        ret.push_back(cur);
        for(int i=1;i<encoded.size();i++){
            ret.push_back(cur^encoded[i]);
            cur=ret.back();
        }
        return ret;
    }
};
// @lc code=end