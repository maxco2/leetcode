//
// @lc app=leetcode.cn id=196183626 lang=cpp
//
// [196183626] clone-graph [克隆图]
//
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> mem;
    Node* dfs(Node* n){
        if(!n) return nullptr;
        if(mem.count(n)) return mem[n];
        Node* nn=new Node(n->val);
        mem[n]=nn;
        for(auto t:n->neighbors){
            auto nt=dfs(t);
            nn->neighbors.push_back(nt);
        }
        return nn;
    }
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};
// @lc code=end