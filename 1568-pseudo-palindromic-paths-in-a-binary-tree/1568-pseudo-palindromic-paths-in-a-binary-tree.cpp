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
//intially ek map maintain karke rakhunga
//fir jab bhi leaf node pe pauchunga 
//toh map ko ek function mei pass kardung ajo check karega mera palindromic hai ya nhi based on freq
//ab palindromic check krne ke lie on  the basis of frequencies
//pehel toh agr saare frequencies even hai toh directly palindromic ho jaega
//aur agr odd hai toh sirf ek hi odd hoina chaiye 

//toh mai sirf odd frequency ke lie check karunga agr ek se bhi jaada ka frequency odd nikla
//toh possible nhi palindromic bnanana

    bool check_pseudo_palindromic(unordered_map<int,int> &mp)
    {
        int odd_count=0;
        //isme mai odd freq waale number rakh lunga
        //aur same jaise upar likha hai agr mere odd freq waale 1 se jaada number aagye toh palindrome not possible

        for(auto t:mp)
        {
            int freq=t.second;
            if(freq%2!=0)
            {
                odd_count++;
            }
        }

        if(odd_count>1)
        return false;

        return true;
    }


    void getpaths(TreeNode* root, unordered_map<int,int> &mp,int &count)
    {
        if(root == NULL)
        return;
        
        mp[root->val]++;

        if(root->left==NULL && root->right ==NULL)
        {
            //ab check karunga ki ye pseudo palindormic possible hai
            if(check_pseudo_palindromic(mp))
            {
                count++;
            }
        }


        getpaths(root->left,mp,count);
        getpaths(root->right,mp,count);

        //ab mera ye waale path ka frequencies ka kaam hogaya
        //toh mai return karunga toh is wale ki frequencie ghata dunga kyuki return wala epath mei ye nhi hoga

        mp[root->val]--;
        //aur muje us number ko apne frequecny map se hata dena chaiye agr wo uska freq 0 hota hai toh
        if(mp[root->val]==0)
        {
            mp.erase(root->val);
        }
    }

    int pseudoPalindromicPaths (TreeNode* root) {

        unordered_map<int,int> mp;
        //ye map mera store karega har node->val ki frequencies

        int count=0;
        //ye count mera batayega finally kitne pseudo palindromic paths hao mere tree mei

        getpaths(root, mp,count);

        return count;

       
        

   
    }
};