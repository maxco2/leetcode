//
// @lc app=leetcode.cn id=177730141 lang=cpp
//
// [177730141] find-minimum-time-to-finish-all-jobs [完成所有工作的最短时间]
//
class Solution {
public:
    vector<int> w;
    int n;
    int ans;
    int k;
    priority_queue<int,std::vector<int>,std::greater<int>> q;
    int calc() {
        int res = 0;
        for(int i=0;i<k;++i) q.push(0);
        for(int i=0;i<n;++i){
            auto x=q.top();
            q.pop();
            q.push(x+w[i]);
        }
        while(!q.empty()){
            res=max(res,q.top());
            q.pop();
        }
        ans = min(ans, res);
        return res;
    }

    void simulate_anneal() {
        random_shuffle(w.begin(), w.end());

        for (double t = 1e4; t > 1e-3; t *= 0.90) {
            int a = rand() % n, b = rand() % n;
            int x = calc();
            swap(w[a], w[b]);
            int y = calc();
            int delta = y-x;
            if ((exp(-delta / t) > (double)rand() / RAND_MAX))
                swap(w[a], w[b]);
        }
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        w=std::move(jobs);
        n=w.size();
        srand(0);
        ans=INT_MAX;
        this->k=k;
        for (int i = 0; i < 106; i ++ ) simulate_anneal();
        return ans;
    }
};
// @lc code=end