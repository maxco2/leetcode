//
// @lc app=leetcode.cn id=186982996 lang=cpp
//
// [186982996] decode-string [字符串解码]
//
class Solution {
public:
    enum State{ST,STR,NUM,NUMSTR};
    struct EnStr{
        string tmp;
        int num;
        State s=ST;
    };
    string decodeString(string str) {
        string ret;
        stack<EnStr> sta;
        sta.push({"",0,ST});
        for(auto c:str){
            auto& cur=sta.top();
            auto& s=sta.top().s;
            if(c==']'){
                auto tmpstr=std::move(cur.tmp);
                sta.pop();
                auto num=sta.top().num;
                //cout<<"tmpstr:"<<tmpstr<< "  num:"<<num<<endl;

                for(int i=0;i<num;++i)
                sta.top().tmp+=tmpstr;
                sta.top().s=ST;
                continue;
            }
            if(s==ST){
                if(c-'0'>=0&&c-'0'<=9){
                    sta.top().s=NUM;
                    sta.top().num=(c-'0');
                }else{
                    sta.top().tmp+=c;
                }
            }else if(s==NUM){
                if(c-'0'>=0&&c-'0'<=9){
                    cur.num=cur.num*10+(c-'0');
                }else if(c=='['){
                    sta.push({"",0,ST});
                }
            }
        }
        //cout<<sta.size()<<endl;
        return std::move(sta.top().tmp);
    }
};
// @lc code=end