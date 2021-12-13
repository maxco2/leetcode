//
// @lc app=leetcode.cn id=170433560 lang=cpp
//
// [170433560] letter-combinations-of-a-phone-number [电话号码的字母组合]
//
#define F(a) s+=a;dfs(ret,digits,cur+1,s);while(s.size()!=sz)s.pop_back()
#define G(a,b,c) F(a);F(b);F(c);
#define GG(a,b,c,d) F(a);F(b);F(c);F(d);

class Solution {
public:
    void dfs(vector<string>& ret,string& digits,int cur,string& s){
        if(cur<digits.size()){
            auto sz=s.size();
            switch (digits[cur]){
                case '2':
                    G('a','b','c')
                    break;
                case '3':
                    G('d','e','f')
                    break;
                case '4':
                    G('g','h','i')
                    break;
                case '5':
                    G('j','k','l')
                    break;
                case '6':
                    G('m','n','o')
                    break;
                case '7':
                    GG('p','q','r','s')
                    break;
                case '8':
                    G('t','u','v')
                    break;
                case '9':
                    GG('w','x','y','z')
                    break;
                default:
                    break;
            }
        }else{
            ret.push_back(s);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> ret;
        string s;
        dfs(ret,digits,0,s);
        return ret;
    }
};
// @lc code=end