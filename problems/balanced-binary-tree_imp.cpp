//https://leetcode.com/problems/balanced-binary-tree/

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
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        bool okay =true;
        check(root,0,okay);
        return okay;
    }
    int check(TreeNode* root,int depth,bool &okay){
        if(!okay)
            return -1;
        if(!root)
            return depth;
        int h1=check(root->left,depth+1,okay);
        int h2=check(root->right,depth+1,okay);
        if(abs(h1-h2)>1)okay=false;
        return max(h1,h2);
    }
};
