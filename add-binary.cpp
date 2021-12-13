//
// @lc app=leetcode.cn id=169690979 lang=cpp
//
// [169690979] add-binary [二进制求和]
//
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size()>b.size()) swap(a,b);
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string ret;
        int la=a.size();
        int lb=b.size();
        bool c=false;
        for(int i=0;i<min(la,lb);++i){
            if(a[i]==b[i]){
                if(a[i]=='0'){
                    if(c)
                    ret+='1';
                    else
                    ret+='0';
                    c=false;
                }else{
                    if(c)
                    ret+='1';
                    else
                    ret+='0';
                    c=true;
                }
            }else{
                if(c)
                    ret+='0',c=true;
                else
                    ret+='1',c=false;
            }
        }
        for(int i=min(la,lb);i<max(la,lb);++i){
            if(c){
                if(b[i]=='1') ret+='0';
                else ret+='1',c=false;
            }else{
                ret+=b[i];
            }
        }
        if(c) ret+='1';
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
// @lc code=end