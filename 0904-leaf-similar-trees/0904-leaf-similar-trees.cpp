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

    TreeNode* getsequence(TreeNode* root,vector<int>& res)
    {
        if(root==NULL)
        return NULL;

        if(root->left==NULL && root->right==NULL)
        res.push_back(root->val);

        //ab left aur right push karta jaunga

        root->left=getsequence(root->left,res);
        root->right= getsequence(root->right,res);

        return root;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vector<int> result1;
        vector<int>result2;

        getsequence(root1,result1);
        getsequence(root2,result2);

        if(result1 == result2)
        return true;

        return false;
        
    }
};