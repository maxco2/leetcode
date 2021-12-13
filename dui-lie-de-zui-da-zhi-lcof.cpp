//
// @lc app=leetcode.cn id=179091538 lang=cpp
//
// [179091538] dui-lie-de-zui-da-zhi-lcof [队列的最大值]
//
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(!q.empty()) return mq.front();
        return -1;
    }
    
    void push_back(int value) {
        q.push_back(value);
        while(!mq.empty()&&mq.back()<=value) mq.pop_back();
        mq.push_back(value);
        //while(mq.size()!=1) mq.pop_front();
    }
    
    int pop_front() {
        if(q.empty()) return -1;
        auto f=q.front();
        q.pop_front();
        if(!mq.empty()&&mq.front()==f)
            mq.pop_front();
        return f;
    }
    deque<int> q;
    deque<int> mq;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
// @lc code=end