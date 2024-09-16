class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

        //converting hours to minutes first of all

        vector<int> time;

        for(string s:timePoints)
        {
            int h1=    (s[0]-'0')*10 + (s[1]-'0');
            int minut= (s[3]-'0')*10 + (s[4]-'0');

            int total =h1*60 + minut;

            time.push_back(total);
        }

        int n=time.size();

        sort(time.begin(),time.end());

        int res=INT_MAX;

        for(int i=1;i<time.size();i++)
        {
            cout<<time[i-1]<<endl;
            cout<<time[i]<<endl;
            res = min(res,(time[i]-time[i-1]));

            res=min(res,(abs(time[i]-(time[i-1]+1440))));
        }

        //ab jo tera ye 1440 wala case hoga circular waala wo muje first aur last ke lie compare krke check karna hoga kyuki 
        //jo closest hoga 0 ke circular way mei jaise 23:59 wo end mei hoga mere sorted time vector 
        //isilie i need to compare 0 th index time and last index time in 1440 format

        res=min(res,(time[0]+1440-time[n-1]));

        return res;



        
    }
};