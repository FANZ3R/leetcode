class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        //dekh  muje min subarray nikaalna jisko hatake merea array divisible hojaaye
        //toh mai poore sum ko mod p karta hu toh remaining jo bachega woi hi mera
        //divisible hone se rokrahah hai...lets say wo target hai
        //toh mai ek aisa sbse chota subarray dhundunga jisnka sum target ke barabar hoga

        // thoda bas maths involved haioo isme thoda check karlena
        //bas basicallyy mai prefix sum /ya cumulative sum ka use karunga
        //manle index i to j muje target ka sum deraha toh
        //mai cumulative sum till j - cumulative sum till i kardunga toh muje target miljayega
        
        //aur mai i wale ko rpevious sum bolunga aur iska index apne ke map mei store karlunga
        //thoda maths lagake if (prev%p) =(curr-target+p)%p hota hai toh
        //i will do length check jo subarray ki hogi aur minimum store karta jaunga

        int sum=0;

        for(int x:nums)
        {
            sum=(sum+x)%p;//yhi pe kyu mod karraha hu
            //kyuki sum boht large jaaskta toh long long lena pdskta
            //toh using property of mod iwill add sum by individullay mod krke
        }


        int target=sum%p;

        int n= nums.size();


        if(target==0)
        return 0;

        unordered_map<int,int>mp;
        //ye store kardega puraane sum ka aur uska index

        mp[0]=-1;

        int ans=n;
        int curr=0;

        for(int j=0;j<nums.size();j++)
        {
            curr=(curr+nums[j])%p;

            int remaining = (curr-target+p)%p;

            if(mp.find(remaining)!=mp.end())
            {
                ans=min(ans,j-mp[remaining]);
            }

            mp[curr]=j;
        }

        if(ans==n)//mtlb nhi hua change to possible hi nhi hai mtlb 
        return -1;

        return ans;
        
    }
};