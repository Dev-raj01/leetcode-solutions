//https://leetcode.com/problems/subtree-of-another-tree/submissions/1562468500/

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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       if (!subRoot) {
            return true;
        }
        if (!root) {
            return false;
        }
        if(sametree(root,subRoot))
            return true;
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
    bool sametree(TreeNode* root,TreeNode* sub){
        if(!root && !sub)
            return true;
        if(root && sub && sub->val == root->val)
            return sametree(root->left,sub->left) && sametree(root->right,sub->right);
        return false;
    }
    
};
