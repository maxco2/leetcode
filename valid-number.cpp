//
// @lc app=leetcode.cn id=187680867 lang=cpp
//
// [187680867] valid-number [有效数字]
//
class Solution {
public:
    enum State{A,B,C,D,E,I1,I2,S1,S2};
    bool isnum(char c){return c-'0'>=0&&c-'0'<=9;}
    bool issign(char c){ return c=='+'||c=='-';}
    bool isexp(char c){return c=='e'||c=='E';}
    bool isNumber(string str) {
        State s=A;
        for(auto c:str){
            if(s==A){
                if(isnum(c)){
                    s=I1;
                }else if(issign(c)){
                    s=B;
                }else if(c=='.'){
                    s=C;
                }else{
                    return false;
                }
            }else if(s==B){
                if(c=='.'){
                    s=C;
                }else if(isnum(c)){
                    s=I1;
                }else{
                    return false;
                }
            }else if(s==C){
                if(isnum(c)){
                    s=S2;
                }else{
                    return false;
                }
            }else if(s==I1){
                if(isnum(c)){
                    s=I1;
                }else if(c=='.'){
                    s=S1;
                }else if(isexp(c)){
                    s=D;
                }
                else{
                    return false;
                }
            }else if(s==S1){
                if(isnum(c)){
                    s=S1;
                }else if(isexp(c)){
                    s=D;
                }else{
                    return false;
                }
            }else if(s==S2){
                if(isnum(c)){
                    s=S2;
                }else if(isexp(c)){
                    s=D;
                }else{
                    return false;
                }
            }else if(s==D){
                if(issign(c)){
                    s=E;
                }else if(isnum(c)){
                    s=I2;
                }else{
                    return false;
                }
            }else if(s==E){
                if(isnum(c)){
                    s=I2;
                }else{
                    return false;
                }
            }else if(s==I2){
                if(isnum(c)){
                    s=I2;
                }else{
                    return false;
                }
            }
        }
        if(s==S1||s==S2||s==I1||s==I2){
            return true;
        }else{
            return false;
        }
    }
};
// @lc code=end