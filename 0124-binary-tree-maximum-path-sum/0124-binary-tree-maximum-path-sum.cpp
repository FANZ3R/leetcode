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

    //toh dekh jab mai solve karne jaunga isko toh 3 case hogne theeke
    //firstly agr muje neeche hi milgaya answer toh l+r +root->val
    //but mai isko return nahi karskta kyuki isme left bhi included hai aur right bhi included hai toh agr mai aage pass karunga isko 

    //toh aage ke lie ye valiud path nhi hai na kyuk isme left and right dono included hai path mei sirf ya toh left ya sirf right jaaega
    

    //ab dusra case ya toh sirf right sahi dera hai ya sirf left sahi dera haiu
    // toh iscase me max(l,r)+ root->val;
    //aur isko return karskte kyuki ye baaki path me include hoskta hai

    //aur teesra case sirf root sahi dera baaki na left se sahi mila na hi right se 
    //toh isko include karke fir return bhi krskte kyuki ye baaki path mei jud skta hai

    int solve(TreeNode* root,int &maxsum)
    {
        if(root==NULL)
        return 0;

        //phle to mai left aur right se sum nikaal leta recursively neeche jaake

        int l = solve(root->left,maxsum);

        int r= solve(root->right,maxsum);

        int neeche_hi_ans_milgaya = l+r+root->val;//1

        int koi_ek_sahi_mila =  root->val + max(l,r);//2

        int sirf_root_accha = root->val;//3

        maxsum = max({maxsum, neeche_hi_ans_milgaya, koi_ek_sahi_mila, sirf_root_accha}) ;

        //ab return sirf 2 ya 3 ko hi krskte so

        return max(koi_ek_sahi_mila,sirf_root_accha);
    }




    int maxPathSum(TreeNode* root) {

        int maxsum=INT_MIN;

        solve(root,maxsum);
        
        return maxsum;
    }
};