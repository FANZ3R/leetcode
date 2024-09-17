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

    TreeNode* solve(vector<int>& inorder,vector<int>& postorder,int instart,int inend,int poststart,int postend)
    {

        //ek check agr instart>inend
        //ye check poststart> postend ko bhgi handle karlega

        if(instart>inend)
        return NULL;

        //phle to root banadunga theeke 
        TreeNode* root= new TreeNode(postorder[postend]);

        //ab mai root ko find karunga apne inorder mei
        //taaki left aur right ke elements ko jaan paau

        int i=instart;

        for(;i<inend;i++)
        {
            if(inorder[i]==root->val)
            break;
        }

        //ab left size aur right size define kardunga
        int leftsize = i-instart;
        int rightsize = inend-i;

        root->left = solve(inorder,postorder,instart,i-1,poststart,poststart+leftsize-1);
        //after passing inorder and post order first to elements state karenge left mei aayenge element ka 
        //starting index aur ending index
        //aur next two represent karenge root ke right me aane wale lements ka starting aur ending index

        root->right = solve(inorder,postorder,i+1,inend,postend-rightsize,postend-1);

        return root;


    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        //dekh muje apna tree build karne ke lie 
        //inorder aur post order pass karna hoga
        //toph mai 4 variables ka use karunga basically theeke

        //aur fir index ka proper use karke har recursive call pe tree banaunga
        
        int n=inorder.size();

        int instart=0;
        int inend=n-1; //ye dono tere inorder ke lie

        int poststart=0;
        int postend=n-1;//ye dono tere postorder ke lie
        //n remember postend pe hi mera root hoga tree ka

        return solve(inorder,postorder,instart,inend,poststart,postend);

        
    }
};