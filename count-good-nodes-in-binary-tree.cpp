//https://leetcode.com/problems/count-good-nodes-in-binary-tree/submissions/1562565671/

//can be done by bfs and dfs

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
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
    int dfs(TreeNode* r,int m){
            if(!r) return 0;
            int res = (r->val >= m) ? 1 : 0;
            m=max(m,r->val);
            res+=dfs(r->left,m);
            res+=dfs(r->right,m);
            return res;
    }
};



