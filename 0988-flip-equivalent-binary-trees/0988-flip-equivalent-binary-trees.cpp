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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {

        //dekh muje values check karni padegi poore equivalent ke lie
        if(root1 ==NULL && root2==NULL)
        return true;

        if(root1 == NULL || root2==NULL)
        return false;

        if(root1->val != root2->val)
        return false;


        bool check_not_flipped ;
        //ye check tbke lie jab root1->left aur root2->left same honge aur similarly root2 bbhi
        //mtlb flip nhi kiya hua

        check_not_flipped = flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right);

        bool check_flipped;

        //jab dono flipped honge

        check_flipped = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right,root2->left);

        return check_not_flipped || check_flipped;
       
        
    }
};