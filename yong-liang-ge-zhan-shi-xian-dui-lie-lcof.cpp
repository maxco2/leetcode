//
// @lc app=leetcode.cn id=203734233 lang=cpp
//
// [203734233] yong-liang-ge-zhan-shi-xian-dui-lie-lcof [用两个栈实现队列]
//
class CQueue {
public:
    stack<int> st1;
    stack<int> st2;
    CQueue() {

    }
    
    void appendTail(int value) {
        st2.push(value);
    }
    
    int deleteHead() {
        if(!st1.empty()){
            auto ret=st1.top();
            st1.pop();
            return ret;
        }
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        if(!st1.empty()){
            auto ret=st1.top();
            st1.pop();
            return ret;
        }
        return -1;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
// @lc code=end