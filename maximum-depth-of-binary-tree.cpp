//https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/1561414572/

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
    int rec(TreeNode* root,int k){
        if(!root)
            return k;
        k++;
        int k1=rec(root->left,k);
        int k2=rec(root->right,k);
        return(max(k1,k2));
    }
    int maxDepth(TreeNode* root) {
        return rec(root,0);
    }
};
