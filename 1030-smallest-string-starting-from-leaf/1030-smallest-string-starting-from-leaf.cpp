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

    string lexico(vector<string> &allstrings)
    {
        string ans = allstrings[0];
        for(int i=1;i<allstrings.size();i++)
        {
            if(ans>allstrings[i])
            ans=allstrings[i];
        }

        return ans;

    }

    void dfs(TreeNode* root, vector<string> &allstrings,string temp)
    {
        if(root == NULL)
        return ;

        char ch = (root->val)+'a';
        temp+=ch;

        if(root->left == NULL && root->right ==NULL)
        {//ab dekh muje string leaf se root tak chiaye but isme 
         //but mai jo calculate krra wo root se leave tak hai
         //toh phle to reverse kardunga
         reverse(temp.begin(),temp.end());
            allstrings.push_back(temp);
            return;
        }

        dfs(root->left,allstrings,temp);
        dfs(root->right,allstrings,temp);
    }

    string smallestFromLeaf(TreeNode* root) {

        string temp="";

        vector<string> allstrings;

        dfs(root,allstrings,temp);

        //ab saari strings store hogyi meri allstrings wale vector mei
        //ab mai bas compare kaarlunga konsi sabse lexicographically smallest hai

        return lexico(allstrings); 


        
    }
};