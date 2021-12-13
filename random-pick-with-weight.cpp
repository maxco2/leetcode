//
// @lc app=leetcode.cn id=212902958 lang=cpp
//
// [212902958] random-pick-with-weight [按权重随机选择]
//
class Solution {
public:
    int n;
    int sum;
    vector<double> pp;
    Solution(vector<int>& w) {
        n=w.size();
        sum=0;
        for(auto c:w){
            sum+=c;
        }
        double cur=0.0;
        for(auto c:w){
           cur+=(c*1.0/sum);
           pp.push_back(cur);
        }
        pp.back()=1.0;
    }
    
    int pickIndex() {
        if(n==1) return 0;
        double p=rand()*1.0/RAND_MAX;
        auto it=lower_bound(pp.begin(),pp.end(),p);
        return it-pp.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end