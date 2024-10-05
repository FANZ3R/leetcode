class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        //sabse best ttareeka hai sliding window se karke 
        //store karlunga frequency s1 ki vector mei 26 size ke 
        //fir s1 ke size ka sliding window chalaunga s2 mei
        //aur uski bhi frequency maintain karunga 
        //agr frequecny ke vector same hue to true

        int n=s1.size();
        int m=s2.size();

        if(n>m)
        return false;

        vector<int> s1_freq(26,0);
        vector<int> s2_freq(26,0);

        for(char ch:s1)
        {
            s1_freq[ch-'a']++;
        }

        int i=0;
        int j=0;

        while(j<m)
        {
            s2_freq[s2[j]-'a']++;

            //ab muje shrink kab karni hai window 
            //jab mera sliding window ka size s1 ki string se bada hojaeega
            if(j-i+1>n)
            {
                s2_freq[s2[i]-'a']--;
                i++;
            }

            if(s1_freq == s2_freq)
            return true;

            j++;
        }

        return false;
        
    }
};