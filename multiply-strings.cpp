//
// @lc app=leetcode.cn id=198337128 lang=cpp
//
// [198337128] multiply-strings [字符串相乘]
//
class Solution {
public:
    vector<int> add(const vector<int>& n1,const vector<int>&n2){
        if(n1.size()<n2.size()) return add(n2,n1);
        int c=0;
        int sz=max(n1.size(),n2.size());
        vector<int> ret;
        for(int i=0;i<sz;++i){
            int tmp=n1[i]+c;
            if(i<n2.size()){
                tmp+=n2[i];
            }
            ret.push_back(tmp%10);
            c=tmp/10;
        }
        if(c) ret.push_back(c);
        return ret;
    }

    vector<int> to_vec(string& s){
        vector<int> ret;
        for(auto c:s){
            ret.push_back(c-'0');
        }
        return ret;
    }

    vector<int> mul(const vector<int>& n1,int n2,int zeros=0){
        int t=0;
        vector<int> ret;
        for(int i=0;i<zeros;++i) ret.push_back(0);
        for(int i=0;i<n1.size()||t;++i){
            if(i<n1.size()) t+=n1[i]*n2;
            ret.push_back(t%10);
            t/=10;
        }
        while(ret.size()>1&&ret.back()==0) ret.pop_back();
        return ret;
    }

    

    void debug(vector<int>& n){for(auto i=n.rbegin();i!=n.rend();++i)cout<<(*i);cout<<endl;}
    
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
        //if(num1.size()<num2.size()) return multiply(num2,num1);
        //if(num1.size()==num2.size()&&num1<num2) return multiply(num2,num1);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        auto n1=to_vec(num1);
        vector<int> ret;ret.push_back(0);
        vector<int> tmp;
        int cnt=0;
        int zeros=0;
        for(auto c:num2){
            if(c!='0'){
                tmp.clear();
                for(int i=0;i<cnt;++i) tmp.push_back(0);
                tmp.insert(tmp.end(),n1.begin(),n1.end());
                ret=add(ret,mul(tmp,c-'0'));
                //debug(ret);
            }
            cnt+=1;
        }
        string t;
        for(auto i=ret.rbegin();i!=ret.rend();++i){
            t+=('0'+(*i));
        }
        return t;
    }

};
// @lc code=end