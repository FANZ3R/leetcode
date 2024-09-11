class Solution {
public:
    int minBitFlips(int start, int goal) {

        int maxi=max(start,goal);

        int count=0;
        while(maxi)
        {
            count++;
            maxi/=2;
        }

        int ans=0;

        while(count--)
        {
            int ith_bit1=(start&1);
            int ith_bit2=(goal&1);

            if(ith_bit1 != ith_bit2)
            ans++;

            start=start>>1;
            goal=goal>>1;
        }


        return ans;

        
    }
};