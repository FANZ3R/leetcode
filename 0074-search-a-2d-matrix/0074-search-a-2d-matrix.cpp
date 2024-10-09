class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // ab efficiently solve karne ke lie wo bhi logarithmic mei
        // dekh tere dimaag mei hamesa aana chaiye kyuki sorted hai toh binary search 
        //abs is question mai bas muje mapping ka trick pata karna hai 1 d index ko 2 d mai
        //toh jo trick hota hai wo 1d (index/number of cols) se gives me its respective row
        //and 1d index%number of rows gfives me its respective column
        //toh bas yehi use karna hai

        int m=matrix.size();
        int n=matrix[0].size();

        int start = 0;
        int end = m*n-1;


        while(start<=end)
        {
            int mid= start +(end-start)/2;

            if(matrix[mid/n][mid%n] == target)
            {
                return true;
            }
            else if(matrix[mid/n][mid%n] > target)
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        } 

        return false;
    }
};