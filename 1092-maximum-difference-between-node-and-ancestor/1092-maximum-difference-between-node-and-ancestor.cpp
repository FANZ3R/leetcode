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

    //brute force approach
    //mai isme har root pe jaunga fir uske har child pe chalajaunga
    int maxd;

    void maxdiff(TreeNode* root, TreeNode* child)
    {
        if(root==NULL || child==NULL)
        return;

        maxd=max(maxd,abs(root->val-child->val));

        maxdiff(root,child->left);
        maxdiff(root,child->right);

        return ;
    }


    void findmaxdiff(TreeNode* root)
    {
        if(root==NULL)
        return ;

        maxdiff(root,root->left);
        maxdiff(root,root->right);
        

        findmaxdiff(root->left);
        findmaxdiff(root->right);

        return ;
    }


    int maxAncestorDiff(TreeNode* root) {

        //har path pe jaaunga aur uske child ke difference se max aur min nikaal lunga

        maxd=-1;

        findmaxdiff(root);
        return maxd;
        
    }
};