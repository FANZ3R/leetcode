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

//dekh isko mai level waale tareeke se karskta hu
//but mai bfs call karunga target node se kyuki usse k level pe saare nodes mere answer honge
//but ek issue hai bfs mai target ko root maan ke kar toh lunga
//but mai parent pe wapis nahi jaaskta
//kyuki first example mei dekh answer  1 bhi hai mera toh wo ulte direction mei jaate hue level 2 pe hai
//toh mai left aur right nodes pe toh jaata hi hu par is case mei mai parent pe bhi jaaunga node ke
//aur mai parent store karta rahunga map mei har node ka jisme bhi valid hai

    unordered_map<TreeNode*,TreeNode*> parent;
        //        child      parent

    //dekh mai sotre karung aprent using inorder traversal
    void storeParent_using_Inorder(TreeNode* root)
    {
        if(root ==NULL)
        return;

        //agr root ka left hoga toh left ka parent root hoga
        if(root->left)
            parent[root->left]=root;

        storeParent_using_Inorder(root->left);

        //agr root ka right hoga toh root ke right ka parent root hoga
        if(root->right)
            parent[root->right]=root;

        //ab right side ke lie parents ko check karugna
        storeParent_using_Inorder(root->right);
    }


    //ab mere parent store hogaye theeke 
    //ab bas muje bfs call karna hai
    //aur ek visited bhi maintain karna padega kyuki mai target se run karunga bfs
    //but mai parent ko bhi visit krra hu toh jab uske left aur right ko visit karra hunga
    // toh left aur right se wapis parent yaani ki target pe aajunga toh ye avoid karne ke lie i will have to keep visited as well
    //aur jab us level pe aajuanga toh jitne bhi nodes honge us level ke wo sab ans honge mere

    void bfs(TreeNode* target, int k,vector<int> &ans)
    {
        if(target==NULL)
        return ;



        unordered_set<int> visited;

        queue<TreeNode*> q;

        q.push(target);

        visited.insert(target->val);
        
        int level=0;

        while(!q.empty())
        {
            //jaise hiu level == k hoga toh jitne bhi nodes honge is level pe wo sab ans hojaynege mere

            if(level==k)
            break;
            //break kyuki wo saare nodes q me honge ..toh mai loop se bahar aakr store karlunga unhe

            int n=q.size();
            //har level ke lie run karna hai isilie while(n--) waala code

            while(n--)
            {
                TreeNode* node=q.front();

                q.pop();

                if(node->left && !visited.count(node->left->val))
                {
                    q.push(node->left);
                    visited.insert(node->left->val);
                }

                if(node->right && !visited.count(node->right->val))
                {
                    q.push(node->right);
                    visited.insert(node->right->val);
                }

                if(parent.count(node) && !visited.count(parent[node]->val))
                {
                    q.push(parent[node]);
                    visited.insert(parent[node]->val);
                }
            }
            level++;

        }

        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }


    }




    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        storeParent_using_Inorder(root);

        vector<int> ans;

        bfs(target,k,ans);

        return ans;


        
    }
};