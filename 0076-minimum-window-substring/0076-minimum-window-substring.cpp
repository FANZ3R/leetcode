class Solution {
public:
    string minWindow(string s, string t) {

        // dekh sliding window se hi karenge isko
        //but dekh bola hua hai ki lowercase and uppercase letters dono present hai
        //toh vector nhi leskte frequency ka hamei map hi banana padega

        //ab dekh logic kya hoga mai map mei t ke saare characters wioth frequecny daal dunga
        //fir required count banaunga jisme t ka length store hoga

        //ab agr wo mere t mei present tha character toh tbhi mai required count ko ghataunga
        //aur baaki unwanted characters ka frequency toh mp[ch]-- krta hi rhunga
        //but required count tbhi ghtega jab mp[ch]>0 hoga
        //kyuki unwanted characters ka count kabhi bhi 0 se jaada nhi jaega

        //aur jbtk required count 0 hoga mai shriink karta jaaunga window size
        //aur us window ka starting index ek start_i pe store karlunga taaki finally substring nikaal saku

        int n=s.size();
        int m=t.size();

        if(m>n)
        return "";

        unordered_map<char,int> mp;

        // mpa mei t ke phle saare character store kardeta
        for(char &ch: t)
        {
            mp[ch]++;
        }

        int required_count = t.size();

        //starting mei jo min window size hoga usko max lelenge
        int minWindowsize=INT_MAX;

        int i=0;
        int j=0;

        int start_i=0;//isme starting index store karunga min window ka

        while(j<n)
        {
            char ch = s[j];

            //ab dekh jab bhi character ka count>0 mtlb wo t mei hoga 
            //aur ab sliding window me agya toh required count tbhi decrease hoga sird
            if(mp[ch]>0)
            {
                required_count--;
            }

            mp[ch]--;
            //aur character ka count toh decrease hi hoga regardless if it is wanted/unwanted

            //ab jabtk mera required count 0 hoga tbtk mai shrink krta rahunga window ko

            while(required_count==0)
            {
                int current_windowsize=j-i+1;

                if(minWindowsize>current_windowsize)
                {
                    minWindowsize=current_windowsize;
                    start_i=i;
                    
                }

                //ab jis i ko hataunga uska mp[ch]++ kardunga
                mp[s[i]]++;

                //ab agr uska count >0 hota toh wo mera wanted character tha
                //toh mtlb maine required character ko hata diya toh required count badh dunga fir

                if(mp[s[i]]>0)
                {
                    required_count++;
                }

                i++;
            }

            j++;

        }

        if(minWindowsize == INT_MAX)
        return "";

        return s.substr(start_i,minWindowsize);



        
    }
    //ye kahani maine tab mei bhi likhi hai waha se bhi chekc karskta hai
};