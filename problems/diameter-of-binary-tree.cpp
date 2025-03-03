//https://leetcode.com/problems/diameter-of-binary-tree/submissions/1561431565/

//easy mid

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
    auto dfs(TreeNode* root){
         if(root==nullptr)
            return 0;
        int left=dfs(root->left);
        int right=dfs(root->right);
        res=max(res,left+right);
        return 1+max(left,right);
    }
    int res=0;
    int diameterOfBinaryTree(TreeNode* root) {    
       dfs(root);
       return res;
    }
};
