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

    map<int,int>mp;

    void DfsSum(TreeNode* root,int level)
    {
        if(root==NULL)
        return ;

        mp[level]+=root->val;

        DfsSum(root->left,level+1);
        DfsSum(root->right,level+1);

    }

    int maxLevelSum(TreeNode* root) {

        //dfs se bhi karskta mai isko
        //dfs mei level send kardunga 
        //aur ek map rakhunga level,uska sum
        //finally us level pe sum update karta rahunga

        DfsSum(root,1);
        //startign me level 1 rahega root ka

        int maxsum=INT_MIN;
        int level=0;

        for(auto t:mp)
        {
            int sum=t.second;
            int l=t.first;

            if(maxsum<sum)
            {
                maxsum=sum;
                level=l;
            }
        }

        return level;
        
    }
};