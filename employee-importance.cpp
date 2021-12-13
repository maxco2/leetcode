//
// @lc app=leetcode.cn id=177783171 lang=cpp
//
// [177783171] employee-importance [员工的重要性]
//
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int ret=0;
        unordered_map<int,Employee*> mem;
        for(auto e:employees) mem.insert({e->id,e});
        {
            auto e=mem[id];
            queue<Employee*> q;
            q.push(e);
            while(!q.empty()){
                e=q.front();
                ret+=e->importance;
                q.pop();
                for(auto s:e->subordinates){
                    q.push(mem[s]);
                }

            }
        }
        return ret;
        
    }
};
// @lc code=end