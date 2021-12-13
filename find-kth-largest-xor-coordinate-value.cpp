//
// @lc app=leetcode.cn id=178992583 lang=cpp
//
// [178992583] find-kth-largest-xor-coordinate-value [找出第 K 大的异或坐标值]
//
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& mx, int k) {
        int m=mx.size();
        int n=mx[0].size();
        vector<int> v;
        for(int i=0;i<m;++i){
            int tmp=mx[i][0];
            //v.insert(lower_bound(v.begin(),v.end(),tmp),tmp);
            for(int j=1;j<n;++j){
                tmp^=mx[i][j];
                mx[i][j]=tmp;
                //v.insert(lower_bound(v.begin(),v.end(),tmp),tmp);
            }
        }
        for(int j=0;j<n;++j){
            int tmp=mx[0][j];
            v.push_back(tmp);
            for(int i=1;i<m;++i){
                tmp^=mx[i][j];
                mx[i][j]=tmp;
                v.push_back(tmp);
            }
        }
        sort(v.begin(),v.end());
        return v[v.size()-k];

    }
};
// @lc code=end