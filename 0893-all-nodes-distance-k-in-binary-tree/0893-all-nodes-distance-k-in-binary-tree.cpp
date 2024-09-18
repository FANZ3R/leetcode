/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    //first lets make parent map
    unordered_map<TreeNode*, TreeNode*> parent;

    void inorder(TreeNode* root)
    {
        if(root==NULL)
        return;

        if(root->left)
        parent[root->left]=root;

        inorder(root->left);

        if(root->right)
        parent[root->right]=root;

        inorder(root->right);

    }

    void bfs(TreeNode* target,int k,vector<int> &result)
    {
        int lvl=0;

        queue<TreeNode*> q;
        q.push(target);

        unordered_set<int> visited;

        visited.insert(target->val);

        while(!q.empty())
        {
            if(lvl==k)
            break;

            int n=q.size();

            while(n--)
            {
                TreeNode* node=q.front();
                q.pop();

                if(node->left && !visited.count(node->left->val))
                {
                    visited.insert(node->left->val);
                    q.push(node->left);
                }

                if(node->right && !visited.count(node->right->val))
                {
                    visited.insert(node->right->val);
                    q.push(node->right);
                }

                if(parent.count(node) && !visited.count(parent[node]->val))
                {
                    visited.insert(parent[node]->val);
                    q.push(parent[node]);
                }
            }
            lvl++;
        }

        while(!q.empty())
        {
            result.push_back(q.front()->val);
            q.pop();
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        inorder(root);

        vector<int> ans;
        bfs(target,k,ans);

        return ans;
        
    }
};