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

    string getAllStrings(TreeNode* root, string curr, vector<string> & st)
    {
        if(root==NULL)
        return "";

        curr+=to_string(root->val);

        //ab agr mera leaf node pe hu to us string ko push kardunga

        if(root->left==NULL && root->right==NULL)
        {
            st.push_back(curr);
        }

        if(root->left!=NULL)//ab agr left hai to left mei traverse karenge
        {
            getAllStrings(root->left,curr,st);
        }

        if(root->right!=NULL)//ab agr mera right hoga to right mei traverse karenge
        {
            getAllStrings(root->right,curr,st);
        }

        return curr;




    }

    int sumNumbers(TreeNode* root) {

        vector<string> st;
        string curr="";

        getAllStrings(root,curr,st);

        int sum=0;

        for(auto s:st)
        {
            int y=stoi(s);
            sum+=y;
        }
        return sum;        
    }
};