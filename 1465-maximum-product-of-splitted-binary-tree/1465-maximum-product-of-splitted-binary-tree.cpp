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

    int M=1e9+7;
    long total=0;
    long maxprod=0;
    int totalsum(TreeNode* root)
    {
        if(root==NULL)
        return 0;

        int leftsum=totalsum(root->left);

        int rightsum=totalsum(root->right);

        int total= root->val+leftsum+rightsum;

        return total;
    }

    int findmax(TreeNode* root)
    {
        if(root==NULL)
        return 0;

        //ab  pehle mai left pe chalajuang pehle poora aur left ka sum calculate krta rhjunga
        int leftsum=findmax(root->left);
        int rightsum=findmax(root->right);

        long subtreesum = root->val+leftsum+rightsum;
        long remainingsum=total-subtreesum;

        maxprod=max(maxprod,subtreesum*remainingsum);

        return subtreesum;

        
    }

    int maxProduct(TreeNode* root) {

        //dekh mai is quesiton mai phle total sum nikaal deta hu 
        //theeke fir mai har phle to bot pe jaunga dfs type lagake  

        total=totalsum(root);

        //ab maine totalsum nikaal liya theeke abmai har node pe jaake sum ko calculate kr lunga

        findmax(root);

        return maxprod%M;


        
    }
};