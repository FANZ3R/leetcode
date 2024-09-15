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
    int ans = 0;

    void maxdiff(TreeNode* root, int maxp, int minp) {
        if (root == nullptr) return;

        
        maxp = max(maxp, root->val);
        minp = min(minp, root->val);

        
        ans = max(ans, max(abs(maxp - root->val), abs(minp - root->val)));

        
        maxdiff(root->left, maxp, minp);
        maxdiff(root->right, maxp, minp);
    }

    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr) return 0;

        maxdiff(root, root->val, root->val);
        return ans;
    }
};
