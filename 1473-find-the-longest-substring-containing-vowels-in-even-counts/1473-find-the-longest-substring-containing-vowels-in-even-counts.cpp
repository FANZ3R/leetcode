class Solution {
public:
    int findTheLongestSubstring(string s) {
        //isme ham bitmask banakae kaam karenge aur fir agr hamne wo bitmask phle hi dekha hua hoga toh
        //usko ham
        

        map<int,int> mp;
        //ye store karega mera maine ye mask phle dekha hai kis index pe

        //aur mera mask 0 wala even wala hoga har vowel pe
        //toh by default even wale ko daaldete 
        //ki agr phle dekha ho kabhi isko 
        //toh add up hota hi rahega

        mp[0]=-1;

        int count=0;
        int ans=0;

        for(int i=0;i<s.size();i++)
        {
            //ab maai bit mask tabhi change karunga agr vowel hai kyuki maine poora 26 bits ka mask leliya
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                count=count^(1<<((s[i]-'a')));
            if(mp.count(count))//agr uska count 0 se jaada hai toh dekha hua hai usko mtlb
            {
                ans=max(ans,(i-mp[count]));
                
            }
            else
            {
                mp[count]=i;
            }
        }

        

        return ans;

    }
};