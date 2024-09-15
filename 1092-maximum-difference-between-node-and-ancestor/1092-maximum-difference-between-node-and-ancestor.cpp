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

   
//ab optimal approach mei mai har node ke paas jaane ke waqt maxvalue and minvalue pass karunga us path mei
//aur jaisi mai leaf node hit karunga toh mai difference nikaal lunga maxvalue and min value ka

    int findmaxdiff(TreeNode* root,int maxv,int minv)
    {
        if(root==NULL)
        return maxv-minv;

        maxv=max(maxv,root->val);
        minv=min(minv,root->val);

        int l=findmaxdiff(root->left,maxv,minv);  // left wale path se difference
        int r=findmaxdiff(root->right,maxv,minv); // right wale path se difference

        return max(l,r); //maxdifference dono paths se


    }

    int maxAncestorDiff(TreeNode* root) {

        //ab initally min v Nd maxv dono root ki value hongi
        int minv=root->val;
        int maxv=root->val;

        return findmaxdiff(root,maxv,minv);


        
    }
};