class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {

        int n=arr.size();
        //mai previos approach mei O(n^2) jaara tha jisme mai
        //har ek ke lie valid paiur dhundra tha thats not worth it
        //isko direct remainder appraoch se krstke

        //dekh muje remainder ko hi pair up karna hai
        //remainder 0 waale ek saath pair up honge
        //agr 7 se divide krra toh remainder 1 wala remainder 6 ke saatha pair up hoga
        //taaki 7 se divisile hoske
        //to generalise remainder i must be paired up with remainder k-i;

        //toh mai remainder ke  count store karlunga from 0 to k-1

        vector<int> remainder(k,0);
        //to store count of remainder fro 0 to k-1;

        for(int x: arr)
        {
           //dekh tera number negative bhi hoskta toh fir remainder bhi -ve askta
           //usko alg se handle karlnege
            int rem = (x%k +k)%k;

            if(rem<0)
            rem+=k; //negative me utna hi k add krdenge postitive ho jaega

            remainder[rem]++; 
        }

        //ab dekh 0 reaminder waalo ke lie alg se karna hoga 
        //kyuki 0 waale sirf 0 waale se hi pair hoga
        //to frequency of remainder 0 should be even to make pairs

        for(int x:remainder)
        {
            cout<<x<<endl;
        }

        if(remainder[0] %2 !=0)
        return false;

        //ab baaki ko check karlenge

        // i ko k-i ka remainder count must be sam
        
        for(int i=1;i<k;i++)
        {
            if(remainder[i]!= remainder[k-i])
            return false;
        }

        return true;
        
    }
};