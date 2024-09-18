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
    int mindepth =INT_MAX;

    void Dfs(TreeNode* root,int depth)
    {
        if(root==NULL)
        return;

        if(root->left==NULL && root->right ==NULL)
        {
            mindepth=min(mindepth,depth);
        }

        Dfs(root->left,depth+1);
        Dfs(root->right,depth+1);
    }

    int minDepth(TreeNode* root) {

        if(root==NULL)
        return 0;

        Dfs(root,1);

        return mindepth;
        
    }
};