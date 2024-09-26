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
int nodes_count=0;

    void findParent(TreeNode* root,unordered_map<TreeNode*, TreeNode*> &parent)
    {
        if(root==NULL)
        return;

        if(root->left)
        parent[root->left]=root;

        if(root->right)
        parent[root->right]=root;

        nodes_count++;

        findParent(root->left,parent);
        findParent(root->right,parent);

    }

    TreeNode* findstart(TreeNode* root, int start)
    {
        if(root == NULL)
        return NULL;

        if(root->val==start)
        return root;

        TreeNode* leftres = findstart(root->left,start);
        if(leftres)
        return leftres;

        return findstart(root->right,start);

    }

    int amountOfTime(TreeNode* root, int start) {

        unordered_map<TreeNode*,TreeNode*> parent;

        findParent(root,parent);

        //ab bfs laga dunga aur visited mei push kardunga start ko 

        //ab start wala node find karta hu pehel toh

        TreeNode* starter= findstart(root,start);

        unordered_set<int> visited;

        queue<TreeNode*> q;

        q.push(starter);

        visited.insert(starter->val);

        int time =0;

        if(nodes_count==1)
        return 0;

        //ab level by level traverse karunga aur har level ke baad time increase kar dunga

        while(!q.empty())
        {
            int n=q.size();
            bool infectionspread = false;

            while(n--)
            {
                TreeNode* node=q.front();
                q.pop();

                if(node->left && !visited.count(node->left->val))
                {
                    q.push(node->left);
                    visited.insert(node->left->val);
                    infectionspread =true;
                }

                if(node->right && !visited.count(node->right->val))
                {
                    q.push(node->right);
                    visited.insert(node->right->val);
                    infectionspread =true;
                }

                if(parent.count(node) && !visited.count(parent[node]->val))
                {
                    q.push(parent[node]);
                    visited.insert(parent[node]->val);
                    infectionspread =true;
                }
            }
            
            //ab mai time tabhi incerase karunga agr mera infection spread hua hoga is level mei
           
                time++;

        }

        return time-1;


        
    }
};