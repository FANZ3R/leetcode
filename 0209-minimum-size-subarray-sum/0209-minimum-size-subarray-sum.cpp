class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        //isko sliding window se kar skta mai

        int n=nums.size();
        
        int i=0;
        int j=0;

        int currsum=0;
        int len=0;
        int result=INT_MAX;
        while(j<n)
        {
            currsum+=nums[j];

            while(currsum>=target)
            {
                result=min(result,j-i+1);
                currsum-=nums[i];
                i++;
            }
            
            j++;


        }

        if(result==INT_MAX)
        return 0;
        
        return result;
        
    }
};