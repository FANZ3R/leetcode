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

    //isko mai recursively bana dunga
        //bas muje dekh starting mei preorder ka starting index hi root hoga
        //aur aisa move krte krte har next index wala kisi ka parent hoga
        //toh mai 4 pointer le lunga pstart, pend ,istart,iend
        //ab preorder ka jo abhi root usko ionorder me dhundke
        //then i will find its index in inorder
        //and then for preorder next abhi pstart+1,pstart+leftcount ye mera preorder ke indices honge 
        //forpreorder root->left aur istart to i-1 root->left 

        //for root->right  ke lie pstart+ leftcount+1 se pend
        //inorder                 i+1,iend 
        
    TreeNode* build(vector<int>& preorder,int pstart, int pend,vector<int>& inorder,int istart, int iend)
    {
        //base case mei agr koi bhi index uske hiogherversion upr cha;lagay
        if((pstart>pend) ||(istart>iend))
        return NULL;

        TreeNode* root = new TreeNode(preorder[pstart]);

        if(pstart == pend)
        {
            //toh mtlb koi children honge hi nahi
            return root;
        }

        int i=istart;
        for(;i<=iend;i++)//agr mai yaha bhi define kardunga i ko toh wo loop ke andr hi rahegi value
        {               //aur muje is for loop ke bahar hamesa i ki value istart hi milegi
            if(inorder[i]==preorder[pstart])
            break;
        }

        //ab i pe mera root ka index stroe hogaya
        int leftcount = i-istart;
        int rightcount = iend-i;

        root->left = build(preorder,pstart+1,pstart+leftcount,inorder,istart,i-1);
        root->right= build(preorder,pstart+leftcount+1,pend,inorder,i+1,iend);

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n=preorder.size();

        return build(preorder,0,n-1,inorder,0,n-1);
    
    }
};