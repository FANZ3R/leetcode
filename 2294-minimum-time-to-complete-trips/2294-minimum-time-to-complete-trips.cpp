class Solution {
public:


    bool possible(vector<int>& time,long long mid,long long total)
    {
         long long trips=0;

         for(int &x:time)
         {
            trips+=(mid/x);
         }

         return trips>=total;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        //dekh pata kaise lagaenge ki binary search se hi solve karna hai ise
        //why binary seasrch>
        //dekh maanle first example  pe pehle maine time 100 liya 
        //toh 100 mei toh easily 5 trips hojaengi toh muje timeline ke left mei jaana padega
        //ab mai 50 leta hu toh usme bhi easily hojaega 
        // toh uske bhi left mei jaunga 
        //ab mai 2 leta hu toh 2 pe trips 3 aari which is elss than 5
        //toh muje ab time line ke right mei jaata hu 
        //ab 3 pe milgaya exaactly 5 ab yhi answer hoga kyuki iskika immediate left invalid answer tha 

        //toh yaha pe mai timeline se khelra hu aur discard karra hu halves ko toh it is sort of binary search
        //left bound toh 1 hoga aur right bound ke lie i will take jo bhinmin element hoga usko total trips karne ka time

        int n=time.size();

        long long l=1;
        long long r= (long long)*min_element(time.begin(),time.end()) * totalTrips;

        while(l<r)
        {
            long long mid=l+(r-l)/2;

            if(possible(time,mid,totalTrips))
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        } 

        return l;


        
    }
};