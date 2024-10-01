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

//dekh jo bhi shortest path hhoga mera wo lowest common ancestor se paas hokar ke jaaega
//toh pehle mai lca nikaal lunga
//aur fir separately path nikaal lnuga source to lca and dest to lca
//aur source to lca ki jitni bhi length hogi uske badle U daal dunga waha pe

    TreeNode* findlca(TreeNode* root, int startValue,int destValue)
    {
        if(root == NULL)
        return root;

        TreeNode* leftN= findlca(root->left,startValue,destValue);
        
        TreeNode* rightN= findlca(root->right,startValue,destValue);

        if(root->val == startValue || root->val == destValue)
        return root;


        if(leftN!=NULL && rightN!=NULL)
        return root;

        if(leftN!=NULL)
        return leftN;

        return rightN;
    }

    bool findPath(TreeNode* lca,int target, string &result)
    {
        if(lca==NULL)
        return false;

        //ab phle lca ko target se check karunga agr ye hi ho toh
        //tb iske lie koi path nhi aayega isilie phle hi chk krlenge

        if(lca->val== target)
        return true;

        //ab agr abhi nhi mila to phle left mei jaunga
        //left mei jaane se phle left ka path string mei daaldunga

        result.push_back('L');

        if(findPath(lca->left,target,result)==true)
        {
            return true;
        }
        //ab agr yaha se nhi mila toh trackback karunga
        result.pop_back();


        //ab wohi right ke lie repeat karunga
        result.push_back('R');

        if(findPath(lca->right,target,result)==true)
        {
            return true;
        }

        result.pop_back();

        //ab agr aise krke khi pe bhi nhi mila toh false return krdenge
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {

        TreeNode* lca = findlca(root,startValue,destValue);

        //lca find karliya ab mai string banunaga

        string lcatos="";//represents source to lca
        string lcatod="";

        findPath(lca,startValue,lcatos);
        findPath(lca,destValue,lcatod);

        //ye do calls meri lcatos and lcatod populate kar dengi


        string ans="";

        //ab jitni bhi length hogi mere lcatos ki utni baar mei U daalunga apni string mei
        //kyuki source to lca jaane ke lie muje upar hi jaana padega

        for(int i=0;i<lcatos.size();i++)
        {
            ans.push_back('U');
        }

        //  aur baaki lcatodestination ka path add kardenge
        ans+=lcatod;

        return ans;
    }
};