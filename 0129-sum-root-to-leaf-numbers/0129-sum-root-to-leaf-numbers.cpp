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

    string getAllstrings(TreeNode* root,vector<string> &st, string curr)
    {
        if(root == NULL)
        return "";

        curr+=to_string(root->val);

        // string s2= to_string(root->val) + getAllstrings(root->right,st);

        if(root->left==NULL && root->right==NULL)
        {
                st.push_back(curr);
            
            // if(st.find(s2)==st.end())
            //     st.insert(s2);
        }

        if(root->left!=NULL)
        getAllstrings(root->left,st,curr);

        if(root->right!=NULL)
        getAllstrings(root->right,st,curr);

        return curr;

    }


    int sumNumbers(TreeNode* root) {

        vector<string> st;

        string curr="";

        getAllstrings(root,st,curr);


        int ans=0;

        for(auto s: st)
        {
            cout<<s<<endl;
            int y=stoi(s);
            ans+=y;
        }    

        return ans;
    }
};