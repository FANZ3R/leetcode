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
    long long kthLargestLevelSum(TreeNode* root, int k) {

        //level order treaversal waala code lagaana bfs ka

        queue<TreeNode*> q;

        q.push(root);

        vector<long long > res;

        while(!q.empty())
        {
            
            long long sum =0;
            int n=q.size();

            for(int i=0;i<n;i++)
            {
                TreeNode* node = q.front();
                q.pop();

                sum+=node->val;

                if(node->left)
                {
                    q.push(node->left);

                }

                if(node->right)
                {
                    q.push(node->right);
                }
            }

            res.push_back(sum);

        }


        sort(res.begin(),res.end(),greater());


       if(res.size()<k)
       return -1;

       return res[k-1];
        
    }
};