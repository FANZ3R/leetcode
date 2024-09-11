class Solution {
public:

    int find1bits(int x)
    {
        int count=0;

        while(x)
        {
            if((x&1)==1)
            count++;

            x=x>>1;
        }
        return count;
    }

    vector<int> sortByBits(vector<int>& arr) {

        //comparator use karna padega to sort on the basis of count of one bits



        auto lambda=[&](int &a,int &b)
        {
            int ca = find1bits(a);
            int cb = find1bits(b);

            if(ca == cb)
                return a<b;
            
            return ca<cb;
        };

        sort(arr.begin(),arr.end(),lambda);

        return arr;

        


        
    }
};