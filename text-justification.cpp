//
// @lc app=leetcode.cn id=186659849 lang=cpp
//
// [186659849] text-justification [文本左右对齐]
//
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
            vector<string> ret;
            int last=0;
            for(int i=0,j=0;i<words.size();){
                int sp=0;
                int cur=words[i].size();
                j=i+1;
                while(cur+sp<maxWidth&&j<words.size()){
                    cur+=words[j].size();
                    sp+=1;
                    j+=1;
                }
                if(cur+sp>maxWidth){
                    cur-=words[--j].size();
                    sp-=1;
                }else if(cur+sp==maxWidth){
                    last=1;
                    string s=words[i];
                    for(int k=i+1;k<j;++k) s+=(" "+words[k]);
                    ret.emplace_back(std::move(s));
                    i=j;
                    continue;
                }
                last=j-i;
                if(sp!=0){
                    string s=words[i];
                    int diff=maxWidth-cur-sp;
                    int psp= diff/sp;
                    int rsp=diff%sp;
                    for(int k=i+1;k<j;++k){
                        for(int l=0;l<=psp;++l)  //sp+psp
                        s+=" ";
                        if(rsp){
                            s+=" ";
                            rsp-=1;
                        }
                        s+=words[k];
                    }
                    ret.emplace_back(std::move(s));
                }else{
                    //only one word
                    string s=words[i];
                    int diff=maxWidth-cur-sp;
                    for(int k=0;k<diff;++k){
                        s+=" ";
                    }
                    ret.emplace_back(std::move(s));
                }
                i=j;
            }
            if(last!=1){
                string s=words[words.size()-last];
                int cur=s.size();
                for(int i=words.size()-last+1;i<words.size();++i){
                    s+=" "+words[i];
                    cur+=1;
                    cur+=words[i].size();
                }
                for(;cur<maxWidth;++cur){
                    s+=" ";
                }
                ret.back()=std::move(s);
            }
            return ret;
    }
};
// @lc code=end