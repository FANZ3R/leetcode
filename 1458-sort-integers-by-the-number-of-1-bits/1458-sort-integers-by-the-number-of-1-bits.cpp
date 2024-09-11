class Solution {
public:

    // int find1bits(int x)
    // {
    //     int count=0;

    //     while(x)
    //     {
    //         if((x&1)==1)
    //         count++;

    //         x=x>>1;
    //     }
    //     return count;
    // }

    //mai bina function ke karunga
    //aur is utility se karna must hai kyuki ye dedeta hai set bits of a number in O(1)

    //is utility ko use karte as __builtin_popcount(int x) -->ye x ke set bits ka count dedega.


    vector<int> sortByBits(vector<int>& arr) {

        //comparator use karna padega to sort on the basis of count of one bits



        auto lambda=[&](int &a,int &b) 
        {//isme & lagana capture data [] (isko capture data bolte)  hn toh capture data mei & lagana tb important hojata
            //agr ham comparator mei main function ke baahar ka kux use krre honge
            
            int ca = __builtin_popcount(a);
            int cb =  __builtin_popcount(b);

            if(ca == cb)
                return a<b;
            
            return ca<cb;
        };

        sort(arr.begin(),arr.end(),lambda);

        return arr;

        


        
    }
};