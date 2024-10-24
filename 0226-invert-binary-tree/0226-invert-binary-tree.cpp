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
    TreeNode* invertTree(TreeNode* root) {
        
        if(root ==NULL)
        return NULL;

        TreeNode *temp=root->left;
        //ab dekh jab mai left ko right se swap kardunga
        //fir mai right ko left se swap karne jaara
        //but left toh change hogaya na
        //isilie left ko pehle hi store kardenge

        root->left = invertTree(root->right);

        root->right = invertTree(temp);

        return root;

    }
};