//
// @lc app=leetcode.cn id=190903828 lang=cpp
//
// [190903828] xu-lie-hua-er-cha-shu-lcof [序列化二叉树]
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string ret;
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            if(cur){
                ret+=" ";
                ret+=to_string(cur->val);
                q.push(cur->left);
                q.push(cur->right);
            }else{
                ret+=" null";
            }
        }
        ret+=" fuck";
        return ret;      
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss;
        stringstream iss;
        ss<<data;
        string cur;
        ss>>cur;
        if(cur=="null"){
            return nullptr;
        }else{
            int val;
            iss<<cur;
            iss>>val;
            TreeNode* root=new TreeNode(val);
            queue<TreeNode**> q;
            q.push(&root->left);
            q.push(&root->right);
            ss>>cur;
            while(cur!="fuck"){ 
                //cout<<"cur:"<<cur<<endl;
                if(cur=="null"){
                    q.pop();
                }else{
                    iss.clear();
                    iss<<cur;
                    iss>>val;
                    //cout<<"val:"<<val<<endl;
                    auto c=q.front();
                    q.pop();
                    (*c)=new TreeNode(val);
                    q.push(&((*c)->left));
                    q.push(&((*c)->right));
                }
                ss>>cur;
            }
            return root;

        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end