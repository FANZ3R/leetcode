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

    TreeNode* dfshelper(TreeNode* root)
    {
        if(root==NULL)
        return root;

        //pehle mai end tak jaunga

        root->left=dfshelper(root->left);
        root->right=dfshelper(root->right);

        if(root->val!=1 && root->left==NULL && root->right==NULL)
        return NULL;

        else
        return root;
    }
    TreeNode* pruneTree(TreeNode* root) {

        TreeNode* temp= dfshelper(root);

        //agr is sab ke baad maine root ko check nahi kiya
        //agr root hi 0 hoga toh null ajaega

        if(root->val==0 && root->left==NULL && root->right==NULL)
        return NULL;
        

        return root;
    }
};