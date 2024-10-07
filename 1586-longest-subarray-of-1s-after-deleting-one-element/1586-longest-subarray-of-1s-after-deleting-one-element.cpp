class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        //ab sliding window appraoach se
        //dekh mera slidign window ka muje shrinkling condition chaioye hota
        //is case me wo condition hoga jbakt mera count_zeros in my window >1 tbtk shrink krta rahunga
        //aur window size bhi mera yaha pe j-i hoga kyuu ki muje 1 element ko delete karna pane window se

        int n=nums.size();
        int maxlen=0;

        int i=0;
        int j=0;
        int count_zeros=0;

        while(j<n)
        {
            if(nums[j]==0)
            {
                count_zeros++;
            }

            while(count_zeros>1)
            {
                if(nums[i]==0)
                {
                    count_zeros--;
                }

                i++;
            }

            maxlen=max(maxlen,j-i);
            j++;


        }

        if(maxlen==n)
        return maxlen-1;
        
        return maxlen;
    }
};