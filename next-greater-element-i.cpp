//
// @lc app=leetcode.cn id=177576696 lang=cpp
//
// [177576696] next-greater-element-i [下一个更大元素 I]
//
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int,int> m;
        for(auto n:nums1){m[n]=-1;}
        for(auto n:nums2){
            while(!s.empty()&&s.top()<=n)
            {
                if(m.count(s.top())) m[s.top()]=n;
                s.pop();
            }
            s.push(n);
        }
        for(auto& n:nums1){
            n=m[n];
        }
        return nums1;
    }
};
// @lc code=end