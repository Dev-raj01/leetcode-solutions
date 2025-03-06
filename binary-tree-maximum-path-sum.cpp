//https://leetcode.com/problems/binary-tree-maximum-path-sum/submissions/1564454729/

//HARD

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
    int maxPathSum(TreeNode* root) {
        int res=root->val;
        dfs(root,res);
        return res;
    }
private:
    int dfs(TreeNode* r,int& res){
        if(!r)  return 0;
        
        int leftMax=dfs(r->left,res);
        int rightMax=dfs(r->right,res);
        
        leftMax=max(leftMax,0);
        rightMax=max(rightMax,0);

        res=max(res,r->val+leftMax+rightMax);
        return r->val + max(leftMax,rightMax);

    }
};
