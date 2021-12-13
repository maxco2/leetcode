//
// @lc app=leetcode.cn id=186227868 lang=cpp
//
// [186227868] get-kth-magic-number-lcci [第 k 个数]
//
class Solution {
public:
#define debug(x) 
//cout<<#x":"<<x<<endl
    unordered_set<int> s;
    using ull = unsigned long long;
    int getKthMagicNumber(int k) {
        if(k==1) return 1;
        priority_queue<ull,vector<ull>,greater<ull>> q;
        q.push(1);
        ull c;
        while(k--){
            c=q.top();
            q.pop();
            auto p1=c*3;
            auto p2=c*5;
            auto p3=c*7;
            debug(c);
            if(!s.count(p1)){
                s.insert(p1);
                q.push(p1);
                debug(p1);
            }
            if(!s.count(p2)){
                s.insert(p2);
                q.push(p2);
                debug(p2);
            }
            if(!s.count(p3)){
                s.insert(p3);
                q.push(p3);
                debug(p3);
            }     
        }
        return c;
    }
};
// @lc code=end