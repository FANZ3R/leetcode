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
    int maxLevelSum(TreeNode* root) {
        
        int level =0;
        int maxsum=INT_MIN;

        //level order traversal karke hi karna hai aur har node ka sum lena hai theeke

        queue<TreeNode*> q;


        q.push(root);

        
        int l=0;

        while(!q.empty())
        {
              
            l++;
            int currlevel_sum=0;

            int n=q.size();

            while(n--)
            {
                TreeNode* node=q.front();
                currlevel_sum+=node->val;

                q.pop();

                if(node->left)
                {
                    q.push(node->left);
                }

                if(node->right)
                {
                    q.push(node->right);
                }
            }

            if(maxsum<currlevel_sum)
            {
                maxsum=currlevel_sum;
                level=l;
            }

        }

        return level;
    }

};