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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        //bas same spiral matrix wala hi question hai 
        // ye ghatta hua wala spiral matrix hai

        //toh mai 4 pointers phle se hi bana dunga 
        //bas ye question spiral matrix 1 ka thoda sa expansion hai
        
        int dir=0;
        //mai chaar directions mei hi move karta rahunga
        // 0 represent karega mera left to right
        // 1 represent karega mera top to down
        // 2 represent karega right to left
        // 3 represetn karega bot to top

        // 4 pointers lelunga  directions ke lie 
        int top=0;
        int right=n-1;
        int left=0;
        int down=m-1;

        //ab matrix define karleta
        vector<vector<int>> matrix(m,vector<int>(n,-1));

        //ab kab tak chalunga ami is quesiton mei jab tk head->next!=null
        //ab ye check waale conditions mai loop kle andfr hi check karskta

        while(head!=NULL)
        {
            if(dir==0)
            {
                for(int i=left;i<=right && head!=NULL;i++)
                {
                    matrix[top][i]=head->val;
                    head=head->next;

                }
                //ab jo constant rehta usko increase ya decrease karte
                top++;
            }

            if(dir==1)
            {
                for(int i=top;i<=down && head!=NULL;i++)
                {
                    matrix[i][right]=head->val;
                    head=head->next;
                }
                right--;

            }

            if(dir==2)
            {
                for(int i=right;i>=left&& head!=NULL;i--)
                {
                    matrix[down][i]=head->val;
                    head=head->next;
                }
                down--;
            }

            if(dir==3)
            {
                for(int i=down;i>=top && head!=NULL;i--)
                {
                    matrix[i][left]=head->val;
                    head=head->next;
                }
                left++;
            }

            dir=(dir+1)%4;
        }
        return matrix;
    }
};