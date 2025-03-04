//https://leetcode.com/problems/same-tree/submissions/1562453025/


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p, q);
    }

    bool check(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;  // Both are null, trees are the same
        if (!p || !q) return false; // One is null, one is not -> different trees
        if (p->val != q->val) return false; // Values don't match -> different trees

        return check(p->left, q->left) && check(p->right, q->right); // Check both subtrees
    }
};