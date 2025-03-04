//https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/1562534508/

//optimised by bfs queue

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                TreeNode* cur=q.front();
                q.pop();
                if(cur->left!=nullptr) q.push(cur->left);
                if(cur->right!=nullptr) q.push(cur->right);
                level.push_back(cur->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};




//recursion approach

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        add(ans,0,root);
        return ans;
    }
    void add(vector<vector<int>>& ans,int l,TreeNode* root){
        if (!root) return;
        if (ans.size() == l) ans.push_back({}); 
        ans[l].push_back(root->val);
        add(ans, l + 1, root->left);
        add(ans, l + 1, root->right);
    }
};
