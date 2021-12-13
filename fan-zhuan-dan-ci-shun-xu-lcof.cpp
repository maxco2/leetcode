//
// @lc app=leetcode.cn id=177789744 lang=cpp
//
// [177789744] fan-zhuan-dan-ci-shun-xu-lcof [翻转单词顺序]
//
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int dst=0;
        int i=0;
        int j=i;
        int w=0;
        while(j<s.size()){
            while(i<s.size()&&s[i]==' ') i++;
            j=i;
            if(i<s.size()){
                while(j<s.size()&&s[j]!=' ') j++;
                reverse(s.begin()+i,s.begin()+j);
                w+=1;
                i=j;
            }
        }
        i=j=0;int sz=0;
        int ww=0;
        while(j<s.size()){
            while(i<s.size()&&s[i]==' ') i++;
            j=i;
            if(i<s.size()){
                while(j<s.size()&&s[j]!=' ') j++;
                for(int ii=i;ii<j;++ii){
                    s[dst++]=s[ii];sz+=1;
                }
                ww+=1;
                if(dst<s.size()&&ww!=w) s[dst++]=' ',sz+=1;
                i=j;
            }
        }
        s.resize(sz);
        return s;
    }
};
// @lc code=end