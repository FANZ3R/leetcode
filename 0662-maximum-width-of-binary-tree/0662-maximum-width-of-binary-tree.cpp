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

    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {

        //dekh mera thingking sahiu tha ki muje index chaiye last not null node ka 
        //but mera dimaag level ordere traversal ki trf nahi gaya
        //jabki level order traversal se mai ise easily karstka hu
        //har level ko push karne ke baad non null nodes ka leftmost aur right most ke indices ka diff +1 nikaal lunga
        //aur har level ke lie compare karlunga 
        //aur jisme bhi max aaya wo return kardunga

        ll maxwidth=0;

        //ab level order traversal karlunga using bfs

        queue<pair<TreeNode*,ll>> q;
        //     node,    index of the node

        q.push({root,0});

        while(!q.empty())
        {
            //ab yaad rakhna agr muje pooora level traverse karne ke baad hi next level pe push karna hota toh 
            //toh ek aur while loop lagate bfs mei while(n--) wala jisme n previous level mei nodes ka size hota


            //aur yahi space hai mera next level pe jaane se phle 
            //is level ke left most aur right most mere pichle loop mei nikaal liye honge 
            //ya traverse kar lie hogne toh traverse krne ke baad maxwidth nikaalne ka option

            ll l= q.front().second;//left most node front pe hoga
            ll r= q.back().second; //right most node back pe hoga

            maxwidth = max(maxwidth,(r-l+1));

            int n=q.size();

            while(n--)
            {
                TreeNode* node = q.front().first;
                ll idx =  q.front().second;

                q.pop();

                if(node->left)
                {
                    q.push({node->left,2*idx+1}); //0 se start krre kyuki root ko
                }

                if(node->right)
                {
                    q.push({node->right,2*idx+2});
                }
            }
        }

        return maxwidth;
        
    }
};