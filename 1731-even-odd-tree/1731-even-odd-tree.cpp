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

    bool checkeven(queue<TreeNode*> q)
    {
       

        vector<int> values;

        while(!q.empty())
        {
            int val=q.front()->val;
            if(val%2==0)
            return false;

            values.push_back(val);
            q.pop();

        }

        //int n=values[0];

        // isme hai strictly increasoing
        for(int i=1;i<values.size();i++)
        {
            cout<<values[i];
            if(values[i]<=values[i-1])
            return false;
        }

        cout<<endl;
        
        return true;

    }

    bool checkodd(queue<TreeNode*> q)
    {
  

        vector<int> values;

        while(!q.empty())
        {

            int val=q.front()->val;
            q.pop();

            if(val%2 == 1)
            return false;

            values.push_back(val);
        }

        //isme hai strictly decreasing order from left to right
        // int n=values[0];

        for(int i=1;i<values.size();i++)
        {cout<<values[i-1]<<" "<<values[i];
            if(values[i]>= values[i-1])
            return false;
        }
        cout<<endl;
        return true;

    }

    bool isEvenOddTree(TreeNode* root) {
        
        //ab bas level order traversal karna hai 
        //level ke hisaab se

        queue<TreeNode*> q;

        q.push(root);

        int level=0;
        while(!q.empty())
        {
            if(level%2==0)
            {
                if(checkeven(q) ==false)
                return false;
            }
            else if(level %2 ==1)
            {
                if(checkodd(q) == false)
                return false;
            }

            int n=q.size();

            while(n--)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left)
                q.push(node->left);

                if(node->right)
                q.push(node->right);


            }
            level++;
        }

        return true;

    }
};