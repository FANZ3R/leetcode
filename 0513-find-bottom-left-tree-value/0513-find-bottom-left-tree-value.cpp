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
        //mai level order traversal lagake aur ek aur queue lelunga 
        //jisme ar level ka queue ka replace karta rahunga usime
        //end mei usme last level ka queue hi bachjayega

        queue<TreeNode*> q;
        q.push(root);

        queue<TreeNode*> temp;

        while(!q.empty())
        {
            temp=q;
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

        return temp.front()->val;
        
    }
};