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
    bool isCompleteTree(TreeNode* root) {
        

        //dekh isko simply bfs se bana skte ham dekh
        //method kya hai ki mai har node ke children push  karta jaaunga queue mei 
        //aur mai ek past mei null dekha hai ki nhai wo variable maintain karta rahunga

        //agr maine past me null dekha hai aur fir muje number milta hai //toh mtlb false
        //kyuki iska mtlb ye hua left child null aur right me khai node hai toh false

        //bfs
        
        queue<TreeNode*> q;
        q.push(root);

        bool past=false;//ye represent karega past mei null dekha hai ki nahi

        while(!q.empty())
        {
            TreeNode* t=q.front();

            q.pop();

            if(t==NULL)
            {
                past=true;
            }
            else
            {
                if(past==true)//mtlb muje node dikha par mera past mei null dekha hua
                return false;

                else
                {
                    q.push(t->left);
                    q.push(t->right);
                }

            }

        }


        return true;
    }
};