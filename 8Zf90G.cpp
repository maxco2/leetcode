//
// @lc app=leetcode.cn id=215799767 lang=cpp
//
// [215799767] 8Zf90G [后缀表达式]
//
class Solution {
public:
    static const int N=1e4+10;
    int nums[N];
    int evalRPN(vector<string>& tokens) {
        int top=0;
        for(auto &s:tokens){
            if(s=="+"){
                int y=nums[--top];
                int x=nums[--top];
                nums[top++]=x+y;
            }else if(s=="-"){
                int y=nums[--top];
                int x=nums[--top];
                nums[top++]=x-y;
            }else if(s=="*"){
                int y=nums[--top];
                int x=nums[--top];
                nums[top++]=x*y;
            }else if(s=="/"){
                int y=nums[--top];  
                int x=nums[--top];
                nums[top++]=x/y;
            }else{
                int x=0;
                bool isn=false;
                for(int i=0;i<s.size();++i){
                    if(s[i]=='-') isn=true;
                    else x=x*10+s[i]-'0';
                }
                x=isn?-x:x;
                nums[top++]=x;
            }
        }
        return nums[top-1];
    }
};
// @lc code=end