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
    int ans=0;

    int calculate(TreeNode* root)
    {
        if(root==NULL)
        return 0;

        //muje bas left aur right ke end tak call karna hai
        // aur fir return karna  hai max (left, right)+1
        //kyuki jo ye node wo apne parent node ko is node ka max of left, right toh apne lie rakhega hi
        //but joo parent node aur is node ko jod ri hai us edge ka count add karke dedega
        //toh max(left,right) jo is node ka hai but parent ko return krne ke lie max(left,right)+1;

        int left=calculate(root->left);
        int right=calculate(root->right);

        ans=max(ans,left+right);
        return max(left,right)+1; 

         
    }
    int diameterOfBinaryTree(TreeNode* root) {

        calculate(root);
        return ans;      
    }
};