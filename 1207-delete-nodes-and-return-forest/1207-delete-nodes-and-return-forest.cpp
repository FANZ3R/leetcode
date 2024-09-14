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


    TreeNode* dfshelper(TreeNode* root,vector<TreeNode*> &result,unordered_set<int> & st)
    {
        if(root==NULL)
        return root;

        //ab phle end tak jaayenge

        root->left=dfshelper(root->left,result,st);
        root->right=dfshelper(root->right,result,st);

        //ab agr node ko delete karna hai muje
        
        if(st.find(root->val)!=st.end())
        {
            //toh phle toh mai uske child ko dekhunga 
            //agr wo nulkl nahi hai to wo different part dedenge aur unhe mai apne result mai daaldunga
            if(root->left!=NULL)
            result.push_back(root->left);

            if(root->right!=NULL)
            result.push_back(root->right);

            //ab kyuki node ko delete karna tha
            //toh uske parent ke lie waaha pe null ajaega

            return NULL;
        }
        else
        {
            return root;
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        //dekh mai isko normal method top to bottom approach se nahi karskta kyuki
        //if i go by normal approach agr maine phle node ko delete kardiya to baaki kabbhi delete hojaega
        //aur suppose neeche bhi kux nodes delete karne thei toh unko account mei nahi lega dnghse
        //aur jo beech ke thei fir wo waise hi reh jaenge

        //so i wil first goto the bottom of the tree and then work my way to the top
        //bottom up aoorach lagaunga fir aisemei

        vector<TreeNode*> result;

        //ek set maintain karunga jisme node delete wale honge
        ///set taaki easily compare karsaku mai

        unordered_set<int> st;

        for(int nums:to_delete)
        {
            st.insert(nums);
        }


        dfshelper(root,result,st);//dfs kyu kyuki mai bottom tak jaaunga phle fir way up kaam klarugna

        //ab end mei root ko daalna hoga agr usko delete nahi karna hai toh

        if(st.find(root->val)==st.end())
        {
            result.push_back(root);
        }

        return result;

        
    }
};