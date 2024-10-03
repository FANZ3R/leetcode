class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        map<int,int> mp;

        mp[0]=-1;

        int n=nums.size();

        int ans=n;

        int totalsum=0;

        for(int x:nums)
        {
            totalsum=(totalsum+x)%p;
        }

        if(totalsum==0)
        return 0;

        int prefixsum=0;

        for(int i=0;i<n;i++)
        {
            prefixsum=(prefixsum+nums[i])%p;
            int check = (prefixsum-totalsum+p)%p;

            if(mp.find(check)!=mp.end())
            {
                ans=min(ans,i-mp[check]);
            }

            mp[prefixsum]=i;
        }
        if(ans ==n)
        return -1;
        
        return ans;
        
    }
};