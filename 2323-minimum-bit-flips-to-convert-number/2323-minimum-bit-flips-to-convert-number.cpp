class Solution {
public:
    int minBitFlips(int start, int goal) {

        //dekh agr ham xor karenge start aur goal ka toh hamei 
        //jaha pe bhi bit differ krri hogi numbers ki whaa pe 1 milega
        //kyuki xor ka result 1 tbbhi aata jb bit differs

        //and finaly after resulting we will count the number of 1 bits

        int result = start ^ goal;


        int ans=0;

        while(result)
        {
            if(result&1 == 1)
            ans++;

            result=result>>1;
        }

        return ans;
        
    }
};