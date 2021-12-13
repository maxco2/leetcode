//
// @lc app=leetcode.cn id=203736996 lang=cpp
//
// [203736996] bao-han-minhan-shu-de-zhan-lcof [包含min函数的栈]
//
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    map<int,int> mem;
    stack<int> s;
    void push(int x) {
        s.push(x);
        mem[x]++;
    }
    
    void pop() {
        if(!s.empty()){
            if(--mem[s.top()]==0){
                mem.erase(s.top());
            }
            s.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return mem.begin()->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
// @lc code=end