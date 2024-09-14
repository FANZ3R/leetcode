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
    TreeNode* pruneTree(TreeNode* root) {

        //bas mai bottom se up karaskta hu code ko
        //phle end pe reach karjaunga

        if(root==NULL)
        return root;

        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);
        //pehle end tak reach karunga nodes ke

        if(root->val==0 && root->left==NULL && root->right==NULL)
        return NULL;

        return root;
        
    }
};