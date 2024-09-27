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

        //dekh mai map ki help lunga nodes ko assign karne ke lie uske parent aur uske nodes mei
        //kyuki unique values derakha hai
        //toh mai har ek integer ke lie har ek node daalunga kab check karne ke baad
        //aur mai ek set maintain karunga saare childrens ke lie
        //aur end mei jo nhi present mei wo hi mera root hoga

        unordered_map<int,TreeNode*> mp;
        //har integer ka node banaunga toh int, treenode type map

        set<int> st;//isme sirf children ko daalunga

        for(auto data:descriptions)
        {
            int p = data[0];
            int c = data[1];
            int l = data[2];

            if(mp.find(p) == mp.end())
            {
                mp[p] = new TreeNode(p); 
            }

            if(mp.find(c) == mp.end())
            {
                mp[c] = new TreeNode(c);
            }

            //ab mei parent nodes aur child nodes ko connect karunga on the basis of l 0,1 ke
            if(l==1)
            {
                mp[p]->left= mp[c];
            }

            else
            {
                mp[p]->right=mp[c];
            }

            //ab child ko insert kardunga apne set mei 
            st.insert(c); 
        }

        //ab mera tree bhi bangya aur saare childs bhi pata hai muje
        //toh bas root nikaalna aur root wohi hoga jo child nodes ke set me nhi hoga
        for(auto data:descriptions)
        {
            int p=data[0];
            if(st.find(p)==st.end())
            {
                return mp[p];
            }
        }

        //aur nhi mila toh null return kardenge

        return NULL;
        
    }
};