class Solution {
public:
    int numTeams(vector<int>& rating) {

        //dekh isko observation se bana skta tu dekh ki
        //kisi bhi element ko agr beech se pakad te ham toh
        //agr mai strictly increasing ki baat karraha toh left mei chote element dhundunga
        //aur right mei mai badei element dhundunga

        // aur agr strictly decreasing ki baat krraha toh left mei bade eleemnt dhundung aaur right mei chote element
        //inka count nikaallunga
        //fir for stricly increasing no of teams = number of elements smaller on left * numer of ele greater in right

        //for eg 2 5 3 4 1
        //strictly increasing ke lie lets take middle element as 3  toh left mei chota ek hi hai 2
        //aur rigght me bhi bad ek hi hai 4 toh team =1*1
        //fir strictly decreasing bhi aisi nikaal skte
        //toh har element ke lie uske left aur right mei increasing aur decreasing elements ka count nikaal lunga

        int n = rating.size();

        //ab dekh 0th index ke left mei kux nhi hoga toh uske left me element kux nhi honge
        //similarly for n-1 th index ke right mei kuyx nhi hoga toh i will
        //take my loop from 1 to n-2

        int teams =0;

        for(int j=1;j<n-1;j++)
        {
            int smaller_left=0;//count of smaller elements on left
            int smaller_right=0;//count of smaller elements on right
            int larger_left=0;  //count of larger elements on left
            int larger_right=0; //count of larger elements on right

            //ab left mei traverse karunga
            for(int k=0;k<j;k++)
            {
                if(rating[k]<rating[j])
                {
                    smaller_left++;

                }
                else if(rating[k]>rating[j])
                {
                    larger_left++;
                }
            }

            //ab right mei traverse karlenge
            for(int k=j+1;k<n;k++)
            {
                if(rating[k] > rating[j])
                {
                    larger_right++;
                }
                else if(rating[k] < rating[j])
                {
                    smaller_right++;
                }
            }

            teams+= (smaller_left * larger_right) + (larger_left * smaller_right);
        }

        return teams;
        
    }
};