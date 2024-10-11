class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        // /toh dekh ab mai optimal soultion se karta hu isko
        //theeke tohdkeh muje hamesa lowest available chair deni hai apne friedn ko
        //toh ye mai priortiy queue se maintain krskta 

        //aur agr khaali hui multiple chairs toh usme se bhi muje miniimum chair nikalwaani hai
        //toh usek lie alg priority queueu lelunga
        //firs pq mei mai departure time aur chairnumber ko daalung jo ki departure time ke basis pe sort hogi

        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> occupied;

        priority_queue<int,vector<int>, greater<int>> free;

        int n=times.size();

        int targetarrival=times[targetFriend][0];

        sort(times.begin(),times.end());



        int chairno=0;

        for(int i=0;i<n;i++)
        {
            int arrival = times[i][0];
            int depart =  times[i][1];

            while(!occupied.empty() && occupied.top().first<= arrival)
            {
                //toh nmtlb mai is chair ko free kar skta hu
                //toh free wale mei is chair number ko daaldunga
                free.push(occupied.top().second);
                occupied.pop();


            }

            if(free.empty())//no free chairs available
            {
                occupied.push({depart,chairno});
                if(arrival == targetarrival)
                return chairno;

                chairno++;
            }
            else
            {
                int leastchairavailable=free.top();

                free.pop();
                if(arrival == targetarrival)
                {
                    return leastchairavailable;
                }

                occupied.push({depart,leastchairavailable});
            }
        }


        return -1;

        
    }
};