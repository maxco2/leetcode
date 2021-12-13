//
// @lc app=leetcode.cn id=192714765 lang=cpp
//
// [192714765] number-of-atoms [原子的数量]
//
class Solution {
public:
    int st[1100];
    map<string,int> mem;
    //return pointer
    int parse_num(string f,int st,int ed,int& res){
        res=0;
        while(st<=ed){
            auto c=f[st];
            if(c-'0'>=0&&c-'0'<=9){
                res=res*10+(c-'0');
            }else{
                if(res==0) res=1;
                return st;
            }
            st++;
        }
        if(res==0) res=1;
        return st;
    }

    int countOfAtoms(string& f,int st,int ed,map<string,int>& cur){
        string lastAtom;
        while(st<=ed){
            auto c=f[st];
            //cout<<"cur char:"<<c<<endl;
            
            if(c=='('){
                if(lastAtom.size()){
                    cur[lastAtom]+=1;
                    //cout<<"last atom:"<<lastAtom<<endl;
                    lastAtom.clear();
                }
                map<string,int> tmp;
                st=countOfAtoms(f,st+1,ed,tmp);
                for(auto& p:tmp){
                    cur[p.first]+=p.second;
                }
            }else if(c==')'){
                if(lastAtom.size()){
                    cur[lastAtom]+=1;
                    lastAtom.clear();
                }
                int num;
                st=parse_num(f,st+1,ed,num);
                for(auto& p:cur){
                    p.second*=num;
                }
                return st;
            }else if(c-'0'>=0&&c-'0'<=9){
                int num;
                st=parse_num(f,st,ed,num);
                cur[lastAtom]+=num;
                lastAtom.clear();
            }else if(c-'A'>=0&&c-'A'<=25){
                if(lastAtom.size()){
                    cur[lastAtom]+=1;
                    lastAtom.clear();
                }
                lastAtom+=c;
                st++;
            }else{
                lastAtom+=c;
                st++;
            }
            //cout<<"last atom:"<<lastAtom<<endl;
        }
        if(lastAtom.size()){
            cur[lastAtom]+=1;
        }
        return st;
    }
    string countOfAtoms(string formula) {
        // E=P+;
        // P=(P)[NUM]|[A-Z][a-z]+ [NUM]
        // NUM=[0-9]+
        int top=0;
        mem.clear();
        countOfAtoms(formula,0,formula.size()-1,mem);
        string res;
        for(auto p:mem){
            if(p.second!=1)
            res+=p.first+to_string(p.second);
            else
            res+=p.first;
        }
        return res;
        
    }
};
// @lc code=end