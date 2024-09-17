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

    //dekh mai left aur right jaskta hu aur zig zag me hi jaana hai
    //but agr left ke baad left hi jaata hu toh naya path start hojaega
    //toh naye paath ke lie fir steps ko fir se initilaize karna padega
    //puraana hatake


    int maxPath=0;

    void solve(TreeNode* root,int steps,bool goleft)
    {
        if(root==NULL)
        return ;

        maxPath=max(maxPath,steps);

        if(goleft==true)
        {
            solve(root->left,steps+1,false);
            solve(root->right,1,true);//ideally toh left jaana tha but right gyaa toh reinitialize krdunga steps apne
            
        }

        else//mtlb muje right jana hai ideally
        {
            solve(root->right,steps+1,true);
            solve(root->left,1,false);
        }

        return ;
    }
    int longestZigZag(TreeNode* root) {

        solve(root,0,true);
        solve(root,0,false);

        return maxPath;
        
    }
};