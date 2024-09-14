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

    int count(TreeNode* root)
    {
        if(root==NULL)
        return 0;

        return 1+count(root->left)+count(root->right);
    }


    bool dfs(TreeNode* root,int i,int nodes_count)
    {
        if(root==NULL)
        return true;

        if(i>nodes_count)
        return false;

        return dfs(root->left,2*i,nodes_count) &&
               dfs(root->right,2*i+1,nodes_count); //ab mei left aur right mei check karunga inko fir
    }


    bool isCompleteTree(TreeNode* root) {

        //using dfs approcah 
        //method ye hai ki agr mera index of node count of nodes se jaada hogye 
        //toh wo left most nhai hai //mtlb wo right mei hai khi instead of left

        //so pehle to saare nodes count karleta hui

        int nodes_count=count(root);

        //ab mai dfs call karunga index 1 deke
        int i=1;

        return dfs(root,i,nodes_count);
        
    }
};