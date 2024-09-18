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
    int minDepth(TreeNode* root) {
        //isko ham bfs se bhi banaskte level waale code se

        if(root==NULL)
        return  0;

        int depth=1;

        queue<TreeNode*> q;
        q.push(root);


        while(!q.empty())
        {
            //ab kyuki level wala code hai toh while(n-- ) daalna padega
            int n=q.size();

            while(n--)
            {
                TreeNode* node=q.front();
                q.pop();

                //ab yhi pe check karta rahunga har ek ke lie ki leaf node toh nhi hai
                //agr leaf node toh depth return kardugna kyuki yue depth pehli baar seen hori hai

                if(node->left==NULL && node->right==NULL)
                return depth;

                if(node->left)
                q.push(node->left);

                if(node->right)
                q.push(node->right);
            }

            depth++;
        }

        return -1;
        
    }
};