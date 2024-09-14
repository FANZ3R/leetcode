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

    vector<vector<int>> result;

    void fill(TreeNode* root, vector<int> &temp,int sum,int targetSum)
    {
        if(root==NULL)
        return;

        sum+=root->val;
        temp.push_back(root->val);

        if(root->left==NULL && root->right==NULL)
        {
            if(sum==targetSum)
            {
                result.push_back(temp);
            }
            //aur agr tera leaf node hai aur sum temp ke barabar nahi hai 
            //toh mai popback karunga

                temp.pop_back();
                // sum-=root->val;
            

            return ;
        }

        fill(root->left,temp,sum,targetSum);
        fill(root->right,temp,sum,targetSum);
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<int> temp;

        fill(root,temp,0,targetSum);
        
        return result;

        
        
    }
};