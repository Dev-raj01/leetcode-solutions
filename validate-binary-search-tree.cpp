//https://leetcode.com/problems/validate-binary-search-tree/

//medium done by bfs


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return bfs(root, LONG_MIN, LONG_MAX);
    }

private:
    bool bfs(TreeNode* cur, long long mini, long long maxi) {
        if (cur == nullptr) return true; // Base case
        
        if (cur->val >= maxi || cur->val <= mini) 
            return false; // BST property violated
        
        return bfs(cur->left, mini, cur->val) && bfs(cur->right, cur->val, maxi);
    }
};