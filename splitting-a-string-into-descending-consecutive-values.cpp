//
// @lc app=leetcode.cn id=186067096 lang=cpp
//
// [186067096] splitting-a-string-into-descending-consecutive-values [将字符串拆分为递减的连续值]
//
class Solution {
public:
    vector<int> sub(vector<int>& a){
        vector<int> b;
        reverse(a.begin(),a.end());
        int t=0;
        int c=1;
        for(int i=0;i<a.size();++i){
            if(a[i]-t-c<0){
                t=1;
                c=0;
                b.push_back(a[i]+10-t-c);
            }else{
                b.push_back(a[i]-t-c);
                t=0;
                c=0;
            }
        }
        reverse(a.begin(),a.end());
        while(b.size()!=1&&b.back()==0) b.pop_back();
        reverse(b.begin(),b.end());
        return b;
    }
    void debug(const vector<int>& a){
        for(auto c:a)cout<<c;
        cout<<endl;
    }
    using ll=unsigned long long;
    bool splitString(string s){
        int sz=s.size();
        int st=0;
        vector<int> cur;
        for(int i=1;i<sz;++i){
            st=0;
            vector<int> tmp;
            while(st<i)
            {
                if(s[st]=='0'&&tmp.empty()){
                    st++;
                }else{
                    tmp.push_back(s[st]-'0');
                    st++;
                }
            }
            st=i;
            cur=std::move(tmp);
            if(cur.empty()){
                continue;
            }
            while(st<sz){
                vector<int> tmp;
                auto d=sub(cur);
                    while(st<sz&&tmp.size()<d.size())
                    {
                        if(s[st]=='0'&&tmp.empty()){
                            st++;
                    }else{
                        tmp.push_back(s[st]-'0');
                        st++;
                    }
                    }
                if(tmp.empty()) tmp.push_back(0);
                if(d!=tmp){
                    goto fail;
                }else{
                    cur=tmp;
                }
            }
            return true;
            fail:
            continue;
        }
        return false;
    }
};
// @lc code=end