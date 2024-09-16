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

    string getSubtreeString(TreeNode* root, unordered_map<string,int> &mp, vector<TreeNode*> &ans)
    {
        if(root==NULL)
        return "N";//agr null hoga toh mia string me N daaldung uske lie

        string s = to_string(root->val) + "," + getSubtreeString(root->left,mp,ans) + "," +
                    getSubtreeString(root->right,mp,ans);
                    //comma se mai separate karunga har node ki value ko

        if(mp[s]==1)//mtlb dusri baar dekhra hu isko
        {
            ans.push_back(root);
        } 

        mp[s]++;

        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        //dekh muje agr compare karna hai toh
        //muje store karna padega apna abhi ka path toh

        //mai har path ka string banaunga aur usko store kardunga fir comapre karne ke lie

        //toh mai kya ek string banalunga apne path ki theeke 
        //aur fir use map mei store kardunga
        //aur agr ek baar phle dekha hai use toh tbhi store karunga uska root apne resutl mei
        //kyuki duplicates patani kitne baar hoga but mai jab use doosri baar dekhunga sirf tabhi sotre karunga wrna nahi

        unordered_map<string,int> mp;

        vector<TreeNode*> ans;

        getSubtreeString(root,mp,ans);

        return ans;
              
    }
};