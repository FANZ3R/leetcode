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

//ab isiko string mei na lekr ke direfct number banate hue chalenge 
//aur jaisi mai leaf node reach karunga to total sum mei add krte rahegne

    int getSum(TreeNode* root,int currsum,int &totalsum)
    {
        if(root==NULL)
        return 0;

        currsum=(currsum*10)+ root->val;

        //ab agr leaf node pe aagya
        //toh total sum ko update krdegne

        if(root->left==NULL && root->right == NULL)
        {
            totalsum+=currsum;
        }


        //ab left mei sum banate rahnge
        if(root->left)
        getSum(root->left,currsum,totalsum);

        //ab right mei bhi sum banate chalejaao
        if(root->right)
        getSum(root->right,currsum,totalsum);


        return currsum;
        //kyuki currsum pe hi add hote rhnege numbers recursively
    }


    int sumNumbers(TreeNode* root) {

        int currsum=0;
        int totalsum=0;

        getSum(root,currsum,totalsum);

        return totalsum;        
    }
};