//https://leetcode.com/problems/binary-tree-right-side-view/submissions/1562543062/

//done by bfs queue medium

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
    vector<int> rightSideView(TreeNode* root) {
      vector<int> ans;
      if(!root) return ans;
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty()){
        int size=q.size();
        int level;
        for(int i=0;i<size;i++){
            TreeNode* cur=q.front();
            q.pop();
            if(cur->left!=nullptr) q.push(cur->left);
            if(cur->right!=nullptr)q.push(cur->right);
            level=cur->val;
        }
        ans.push_back(level);
      } 
      return ans; 
    }
};
