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

       return  remove(root,target);

        //agr mai alg se phle remove(root,target) call karunga aur fir
        //aur fir return root karunga
        //toh aise me dekh root remove nahi hoga agr use remove karna hoga wo sirf return NULL karega
        //but our root wouldnt have been removed using this
        //toh root node ko bhi handle krne ke lie 
        //return remove(root,target); ek hi line mei likhna hoga
        
        
    }
};