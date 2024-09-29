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
    int findBottomLeftValue(TreeNode* root) {
        //mai level order traversal lagake aur last level ka front wala element hi mera left child hoga
        //toh bas mai har level ko traverse karne se pehle usme ek variable mei levle ka front element store krlunga
        //end mei usme last level ka queue hi bachjayega aur uska front mere
        //paas stored hoga

        queue<TreeNode*> q;
        q.push(root);

        int ans=0;

        while(!q.empty())
        {
            ans=q.front()->val;
            int n=q.size();

            while(n--)
            {
                TreeNode* node= q.front();
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
        }

        return ans;
        
    }
};