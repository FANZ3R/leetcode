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

    //dekh phle  maio recursively end tak jaunga
    //aur niche hi path calculate karne ki kosis karunga by left + right ke nodes
    //aur kya pata ye wale node se muje max path na mile toh mai 
    //toh mia parent ko max path is node ki +1 ek edge return kardunga kyuuki jab is node ko paernt se jopdenge toh 
    //ek edge aur badh jaayegi

    int ans=0;

    int solve(TreeNode* root)
    {
        if(root == NULL)
        return 0;

        //ab pehle niche jaaunga
        int l = solve(root->left);
        int r = solve(root->right);


        //ab kya pata muje isi node pe apna answer milgya agr 
        ans= max(ans,l+r);
        //l+r kyu kyuki is node ke lie max path hoga left wali edges + right wali edges

        //ab mai parent ko return kardunga is node ka max single side ka path + 1 edge of parent to this node
        return max(l,r)+1;  
    }


    int diameterOfBinaryTree(TreeNode* root) {

        solve(root);

        return ans;

        
        
    }
};