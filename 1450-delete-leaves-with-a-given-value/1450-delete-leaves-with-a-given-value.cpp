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

    TreeNode* remove(TreeNode* root, int target)
    {
        if(root == NULL)
        return NULL;

        root->left = remove(root->left,target);
        root->right = remove(root->right,target);

        if(root->left == NULL && root->right == NULL && root->val == target)
        {
            return NULL;
        }

        return root;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {

        remove(root,target);

        //mera function saare nodes ko to check karlega 
        //but agr last mei root ko bhi delete karna pde 
        //toh wo check muje finally khud se hi karna padega
        if(root->left==NULL && root->right==NULL && root->val==target)
        return NULL;

        return root;
        
    }
};