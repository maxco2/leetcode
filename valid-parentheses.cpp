//
// @lc app=leetcode.cn id=169246124 lang=cpp
//
// [169246124] valid-parentheses [有效的括号]
//
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push('f');
        for(auto c:s){
            switch (c){
                case '(':
                case '{':
                case '[':
                    st.push(c);
                    break;
                case ')':
                    if(st.top()=='('){
                        st.pop();
                    }else{
                        return false;
                    }
                    break;
                case '}':
                    if(st.top()=='{'){
                        st.pop();
                    }else{
                        return false;
                    }
                    break;
                case ']':
                    if(st.top()=='['){
                        st.pop();
                    }else{
                        return false;
                    }
                    break;
                default:
                    return false;
            }
        }
        st.pop();
        if(!st.empty()) return false;
        return true;
    }
};
// @lc code=end