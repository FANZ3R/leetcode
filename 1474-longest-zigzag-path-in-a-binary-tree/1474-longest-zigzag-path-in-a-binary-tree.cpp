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

    //optimised approach 
    //mai hamesa l,r pair bhejunga is node ka next node pe
    //aur zig zag banane ke lie agr mei left mei jaara hu left ko zero kardunga aur right pe left +1 bhejunga
    //tbhi toh mera zigzag path badega phle left fir right then left and vice versa
    //toh mai zig zag path banane ke lie left pe rihgt+1 bhejunga when going left aur right ko zero bhejdunga
    //aur aisi alternate karta rahunga

    int maxPath=0;

    void solve(TreeNode* root, int l ,int r)//l and r har node ka pair represent karenge
    {
        if(root==NULL)
        return;

        maxPath=max({maxPath,l,r});

        solve(root->left,r+1,0);
        solve(root->right,0,l+1);

    }
    int longestZigZag(TreeNode* root) {

        solve(root,0,0);
                // l  r

        return maxPath;
        
    }
};