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

        //agr dono null hue
        if(root1 == NULL && root2 == NULL)
        return true;

        //sirf ek null hua

        if(root1 == NULL || root2 == NULL)
        return false;

        //dekh values pe bhi check karna padega
        //agr root ki values hi match ni karri toh flip karne ka faayeda ni wo waise equal nhi 

        if(root1->val != root2->val)
        return false;

        //ab dekh flip kr bhi ksta aur nhi bhi
        //toh ek baar mai flipped wale pe check karunga aur ek baar notflipped
        //ab dono hi shi hoskte toh agr ek bhi true mila dono me se toh sahi hai true hai

        bool not_flipped = flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right);

        bool flipped     = flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left);

        return flipped || not_flipped;
        
    }
};