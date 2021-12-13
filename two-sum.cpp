//
// @lc app=leetcode.cn id=168789693 lang=cpp
//
// [168789693] two-sum [两数之和]
//
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> s;
        int idx = 0;
        for (auto i : nums)
            s.insert({i, idx++});
        vector<int> res;
        for (auto i = 0; i < nums.size(); ++i)
            {
                int left = target - nums[i];
                if (s.find(left) != s.end() && s[left] != i)
                    {
                        res.push_back(i);
                        res.push_back(s[left]);
                        return res;
                    }
            }
        return res;
    }
};
// @lc code=end