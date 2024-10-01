/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    bool check (ListNode* head, TreeNode* root)
    {
        // dekh jo general wala hota hai root ==null toh return null
        // but is case mei agr tera tera head = null aur root =null simultaneous hua 
        //toh true return kardenge

        //so first we will have to check for linked list
        if(head==NULL)
        return true;

        if(root==NULL)
        return false;

        if(head->val!=root->val)
        return false;

        return check(head->next,root->left) || check(head->next,root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {

        //dekh mera check ek node ko lekr 
        //usse path check kr raha hai

        //but muje har possible source ke lie path check karna hai
        //check function mera sirf ek source ko lekr path ccheck kar raha hai
        //toh muje har possible source se path check karna hai

        //ya toh wo muje starting root se hi miljaye 
        // ya fir recursively mai left aur right mei source ko lekr check karunga

        // aur aisa bhi soskta ki recursively check karte karte root hi null hoijayega
        if(root == NULL)
        return false;

        return check(head,root) ||
               isSubPath(head,root->left) ||
               isSubPath(head,root->right);
        
    }
};