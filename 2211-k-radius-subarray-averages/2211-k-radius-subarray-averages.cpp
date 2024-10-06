class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {

        int n=nums.size();

        int i=0;
        int j=0;

        vector<int> result(n,-1);

        int posi=k;

        int ws=2*k+1;//window size jo hoga wo 2*k+1 hoga

        long long currsum=0;
        while(j<n)
        {
            currsum+=nums[j];

            if(j-i+1==ws)
            {
                long long average =(currsum/ws);
                result[posi]=average;
                posi++;

                currsum-=nums[i];
                i++;
            }

            j++;

        }

        return result;

        
    }
};