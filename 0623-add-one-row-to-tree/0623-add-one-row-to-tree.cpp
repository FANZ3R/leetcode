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

    TreeNode* addrow(TreeNode* root, int val ,int depth,int curr)
    {
        if(root==NULL)
        return NULL;

        //ab mai left aur right mei kab insert karna sahi rahega
        //jab mei depth se just ek upar rahu tab mai left aur right ko easily traverse karskta
        //isilie mai jab depht ke just ek upar hunga tab insert karunga

        if(curr==depth-1)
        {
            //toh phle orginal left aur rihgt ko store karleta hu
            TreeNode* templeft=root->left;
            TreeNode* tempright=root->right;

            root->left=new TreeNode(val);
            root->right=new TreeNode(val);

            root->left->left = templeft;
            root->right->right = tempright;

            //ab return kardenge root ko
            return root;
        }

        //ab agr us depht mei nahi hu toh
        // toh left child aur right child ke lioe call kardunga

        root->left=addrow(root->left,val,depth,curr+1);
        root->right=addrow(root->right,val,depth,curr+1);

        return root;

    }
    

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        //dekh starting mei depth 1 se start hora hai
        //agr muje first depth pe hi node banana hai toh
        //mai naya root banunga aur poraane root ko left child bana dunga 
        //aisa question mei bola huia

        if(depth==1)
        {
            TreeNode* newroot= new TreeNode(val);
            newroot->left=root;

            return newroot;
        }

        //ab agr aisa nahi hai to mai ek naya function call kardunga add root ka 
        int curr=1;//ye mera currdepth bata raha hai

        return  addrow(root,val,depth,curr);
        
    }
};