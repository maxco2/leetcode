//
// @lc app=leetcode.cn id=186258845 lang=cpp
//
// [186258845] maximum-number-of-removable-characters [可移除字符的最大数目]
//
class Solution {
public:
    unordered_set<int> mem;
    bool check(int mid,string& s,string &p,vector<int>& re){
        if(mid==0) return true;
        //cout<<"check mid:"<<mid<<endl;
        mem.clear();
        for(int i=0;i<mid;++i) mem.insert(re[i]);
    
        int n = s.length(), m = p.length();
        int i = 0, j = 0;
        while (i < n && j < m) {
            while(mem.count(i)) i++;
            if(i>=n) break;
            if (s[i] == p[j]) {
                j++;
            }
            i++;
        }
        return j == m;
    }
    int maximumRemovals(string s, string p, vector<int>& re) {
        if(re.empty()) return 0;
        int l=0;
        int r=re.size();
        int ans=0;
        while(l<=r){
            int mid=l+r>>1;
            if(check(mid,s,p,re)) ans=mid,l=mid+1;
            else r=mid-1;
        }
        return ans;
    }
};
// @lc code=end