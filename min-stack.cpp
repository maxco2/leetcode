//
// @lc app=leetcode.cn id=178742844 lang=cpp
//
// [178742844] min-stack [最小栈]
//
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int val) {
        if(val==mm){
            count_of_mm+=1;
        }else if(val<mm){
            mm=val;
            count_of_mm=1;
        }
        p.push_back(val);
    }
    
    void pop() {
        auto last=p.back();
        if(last==mm){
            p.pop_back();
            count_of_mm-=1;
            if(count_of_mm==0) mm=INT_MAX;
            if(count_of_mm==0&&!p.empty()){
                count_of_mm=1;
                mm=p[0];
                for(int i=1;i<p.size();++i){
                    if(p[i]==mm){
                        count_of_mm+=1;
                    }else if(p[i]<mm){
                        mm=p[i];
                        count_of_mm=1;
                    }
                }            
            }
        }else{
            p.pop_back();
        }
    }
    
    int top() {
        return p.back();
    }
    
    int getMin() {
        return mm;
    }
    vector<int> p;
    int mm=INT_MAX;
    int count_of_mm=0;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end