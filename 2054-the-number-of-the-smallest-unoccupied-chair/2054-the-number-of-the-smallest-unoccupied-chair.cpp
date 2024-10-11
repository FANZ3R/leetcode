class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        //dekh pehle to brute force se hi kardenge isko
        //mai chair vector lelunga ek n size ka hi
        //aur usme -1 daaldunga initially
        //aur agr chair ki value less than hai arrival time friend ke 
        //friends ko phle sort karunga based on arrival time 
        //aur agr less hai value toh chiar waale vector mei mai uska departure time daal dunga
        //kyuki agr departure opf prev is less than arrival of next toh naye bande ko bitha skte isme

        //aur mai target arrival time ko pehle hi store karlunga
        //aur har time ke lioe chioar vector ko iterate karunga 
        //aur jaisi hi daaldunga value toh break karjuanga taaki aage kisi glt index mei na daaldu value ko in brute force approach

        int n=times.size();

        vector<int> chairs(n,-1);

       

        int targetarrivaltime =times[targetFriend][0];

         //pehle srot ont the basis of arrival time
        sort(times.begin(),times.end());

        for(vector<int> &time:times)
        {
            int arrival = time[0];
            int depart =  time[1];

            for(int i=0;i<n;i++)
            {
                if(chairs[i]<=arrival)
                {
                    chairs[i]=depart;

                    if(arrival==targetarrivaltime)
                    {
                        return i;
                    }

                    break;
                    //kyuki chairs[i] pe depart daal diya ab aage waali chairs khaali hongi
                    //but muje sbse choti pe daalna tha maine daal diya toh break karjaunga
                }
            }
        }

        return -1; 
      
    }
};