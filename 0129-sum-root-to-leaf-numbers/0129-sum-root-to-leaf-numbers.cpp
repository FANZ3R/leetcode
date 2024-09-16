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

    int getSum(TreeNode* root, int currsum)
    {
        if(root==NULL)
        return 0;

        currsum = (currsum*10)+root->val;

        //ab agr leaf node hai toh currsum ko return kardunga
        if(!root->left && !root->right)
        return currsum;

        //ab mai left se sum nikaal lunga 
        int l=getSum(root->left,currsum);

        //aur right se sum nikaal lunga
        int r= getSum(root->right,currsum);

        //at the end dono ke left se aur right se sum ko addd kardunga
        return l+r;
    }

    int sumNumbers(TreeNode* root) {

        //directly aur simple usse bhi karskte hai
        int currsum=0;
        return getSum(root,currsum);
        
    }
};