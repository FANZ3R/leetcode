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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        //ek mei to mai store kaunga saare nodes jo ki maine banaye abhitak
        //aur dusre mei mai store karunga saare children nodes taaki finally return karsaku root

        unordered_map<int,TreeNode*> mp;

        set<TreeNode*> st;
        //this is for all the childrens

        for(auto it: descriptions)
        {
            int parent = it[0];
            int child  = it[1];

            //ab check karunga kya main pehle se child ya parent ke lie node banaya hua hai

            if(mp.find(parent) == mp.end())
            {
                mp[parent] = new TreeNode(parent);
            }

            if(mp.find(child) == mp.end())
            {
                mp[child] = new TreeNode(child);
            }

            if(it[2]==1)
            {
                mp[parent]->left=mp[child];
            }
            else
            {
                mp[parent]->right = mp[child];
            }
            
            st.insert(mp[child]);


        }

        for(auto it: descriptions)
        {
            int p=it[0];
            if(st.find(mp[p])==st.end())
            {
                return mp[p];
            }
        }

        return NULL;
        
    }
};