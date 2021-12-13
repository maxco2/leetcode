//
// @lc app=leetcode.cn id=213282219 lang=cpp
//
// [213282219] restore-ip-addresses [复原 IP 地址]
//
class Solution {
public:
    vector<string> ret;
    void dfs(int idx,int cur,string& s,string& ip){
        if(idx==s.size()){
            if(cur==4&&ip.size()==s.size()+3){
                ret.push_back(ip);
            }
            return;
        }
        if(cur==4) return;

        int tmp=0;
        int ipsz=ip.size();
        for(int i=idx;i<s.size()&&i<idx+3;++i){
            tmp=tmp*10+(s[i]-'0');
            if(tmp>=0&&tmp<=255){
                if(cur!=0)
                ip+='.';
                ip+=to_string(tmp);
                dfs(i+1,cur+1,s,ip);
                while(ip.size()!=ipsz) ip.pop_back();
            }else{
                break;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string ip;
        dfs(0,0,s,ip);
        return ret;
    }
};
// @lc code=end