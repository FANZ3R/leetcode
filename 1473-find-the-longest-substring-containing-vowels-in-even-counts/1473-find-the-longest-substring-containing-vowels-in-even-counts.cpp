class Solution {
public:
    int findTheLongestSubstring(string s) {

        //direct integer mask leke bhi hojaaega ye
        
        //mai mask ki msb ko a se represent karunga
        //00000
        //uoiea //aise represent honge ye

        //aur map mei index store karunga ki phle ye state dekha hai kabhi 

        unordered_map<int,int> mp;
        int mask=0;

        mp[mask]=-1;

        int ans=0;


        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a')
            {
                mask=mask^(1<<0);
                //a kyuki msb hai toh usko 0 time shift krke
            }
            else if(s[i]=='e')
            {
                mask=mask^(1<<1);
            }
            else if(s[i]=='i')
            {
                mask=mask^(1<<2);
            }
            else if(s[i]=='o')
            {
                mask= mask^(1<<3);

            }
            else if(s[i]=='u')
            {
                mask=mask^(1<<4);
            }

            if(mp.find(mask)!=mp.end())
            {
                ans=max(ans,(i-mp[mask]));
            }
            else
            {
                mp[mask]=i;
            }

        }

        return ans;

    }
};