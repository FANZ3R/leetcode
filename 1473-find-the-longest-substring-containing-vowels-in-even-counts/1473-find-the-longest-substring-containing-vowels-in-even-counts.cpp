class Solution {
public:
    int findTheLongestSubstring(string s) {

        //isko sliding window se nahi banaskta kyuki manle abhi vowel odd aare par baad mei even aaskte
        //but sliding window waale methode se mai skip kardunga abhi9 odd pe hi

        //ab mai isko map leke bana skta string ka 
        //string mei mai sirf bits store karunga vowels ki aur unki bit maintain karta rahugna
        //00000  represent karega aeiou ko 0 ke lie even 1 ke lie odd

        unordered_map<string,int>mp;

        string currstate="00000";

        mp[currstate]=-1;

        //by default saare 0 honge to saare even hi hai
        //toh usko pehle hi daaldenge compare krne ke lie if we get string 1 character ya further jo maintaing 
        //krti ho ye rule

        //ab state ke lie bits ko banayenge integer vector

        vector<int> state(5,0);

        //00000 aeiou in order maintain karega

        int ans=0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a')
            {
                state[0]=(state[0]+1)%2;
                // %2 se hamesa even odd ka maintain rakhunga mai
            }
             if(s[i]=='e')
            {
                state[1]=(state[1]+1)%2;
                
            }
             if(s[i]=='i')
            {
                state[2]=(state[2]+1)%2;
                
            }
             if(s[i]=='o')
            {
                state[3]=(state[3]+1)%2;
                
            }
             if(s[i]=='u')
            {
                state[4]=(state[4]+1)%2;
                
            }


            string currstate="";

            //ab currstate build karunga

            for(int j=0;j<5;j++)
            {
                currstate+=to_string(state[j]);
            }

            if(mp.find(currstate)!=mp.end())
            {
                ans=max(ans,(i-mp[currstate]));
            }
            else
            {
                mp[currstate]=i;
            }
        }

        return ans;

        
    }
};