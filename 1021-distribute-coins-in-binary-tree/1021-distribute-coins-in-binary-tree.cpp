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

    //dekh mai isme pehle nodes ke enbd mei chale jaaunga
    //fir mai calculate karunga kitne moves ki jroorat hai muje
    //by uske left se kitne extra coins aaye aur right se kitne extra coins aaye
    //ab maanle mere node mei left se x aye aur right se y aaye
    //tyoh mai apne papa/parent ko 1 chodke baaki sab dedunga 

    //so i will (x+y+root->val)-1 to my papa

    int findmoves(TreeNode* root,int & moves)
    {
        if(root==NULL)
        return 0;

        //pehle end tak jaunga kyuki recursively mai calculate karskta huy fir
        //parent ko kitna dena aur kitne moves chaiye

        int l = findmoves(root->left,moves);
        int r = findmoves(root->right,moves);

        moves+= abs(l) + abs(r);
        //abs kyu kyuki neeche se -1 bhi ya negative me jaada number bhi aaskta
        //ye represent karega ki mai de ni skta blki muje jroorat hai coin ki
        //aur left se extra se jitne extra coins aayenge unko distribute krne ke lie utne hi moves lgnenge
        //simmilarly right se extra coins ke lie bhi utne hi moves lageneg

        return l+r+root->val-1;

        //aur return krte hue mai abs nhi lunga kyuki ye represent krra hai extra coins ko jo 
        //ki negative mei need ko represent krre hai
        //dry run krke dekh smj aayega

    }

    int distributeCoins(TreeNode* root) {

        int moves=0;

        findmoves(root,moves);

        return moves;

        
    }
};