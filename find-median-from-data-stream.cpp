//
// @lc app=leetcode.cn id=178166452 lang=cpp
//
// [178166452] find-median-from-data-stream [数据流的中位数]
//
class MedianFinder {
public:
    vector<int> f;
    /** initialize your data structure here. */
    MedianFinder() {
        f.clear();
    }
    
    void addNum(int num) {
        f.insert(lower_bound(f.begin(),f.end(),num),num);
    }
    
    double findMedian() {
        if(f.size()%2==0){
            auto f1=f[f.size()/2];
            auto f2=f[f.size()/2-1];
            return (f1+f2)/2.0;
        }else{
            return f[f.size()/2];
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end