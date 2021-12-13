//
// @lc app=leetcode.cn id=176615529 lang=cpp
//
// [176615529] xor-queries-of-a-subarray [子数组异或查询]
//
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int first=arr[0];
        for(int i=1;i<arr.size();++i){
            first^=arr[i];
            arr[i]=first;
            //cout<<first<<endl;
        }
        vector<int> ret;
        for(int i=0;i<queries.size();++i){
            auto r=queries[i][1];
            auto l=queries[i][0];
            if(l!=0){
                ret.push_back(arr[l-1]^arr[r]);
            }else{
                ret.push_back(arr[r]);
            }
        }
        return ret;
    }
};
// @lc code=end