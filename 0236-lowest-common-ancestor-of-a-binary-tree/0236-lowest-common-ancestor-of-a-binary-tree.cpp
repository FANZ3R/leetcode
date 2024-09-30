/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //dekh lowest common ancestor ke lie mere alg alg case hoskte
        //agr ek node ke left se p mila and right se q mila toh wo hi agr sbse lowest node aisa hai toh lca
        //but aisa bhi hoskta ki p ya q dono ek hi side pe ho to aise mei muje
        //toh aise mei jo hi phle milega p ya q mese wo hi mera lca hojaega

        if(root == NULL)
        return root;

        TreeNode* leftN = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightN = lowestCommonAncestor(root->right,p,q);

        if(root == p || root ==q)
        return root;

        //ab agr dono side se milgaya mtlb ek leftN se p/q aur rightN se q/p
        //toh wo hi lca hojaega
        if(leftN!=NULL && rightN!=NULL)
        return root;         

        //ya toh ek side null hogi toh jo not null hoga wo hi lca dedega
        if(leftN!=NULL)
        return leftN;

        //ab bacha rightN agr wo not null hai ya dono hi null
        // toh return rightN wo handle karlega
        
        return rightN;

    }
};