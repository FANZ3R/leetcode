class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        //bas same hai anagram find kartlunga aur unka starting index vector mei store krte jaunga

        //toh i will make frequency vectors for both s and p
        //ab mai usme pehle p ka frequency store karlunga
        //aur fir sliding window lagaunga s pe
        //ab mai p size ki slinding window ka frequency maintain karunga 
        //agr same aaya frequency vector toh starting index push kardunga result vector mei

        int n = p.size();
        int m = s.size();

        vector<int> freq_p(26,0);
        vector<int> freq_s(26,0);

        for(char ch:p)
        {
            freq_p[ch-'a']++;
        }

        vector<int> result;

        int i=0;
        int j=0;

        while(j<m)
        {
            freq_s[s[j]-'a']++;

            //ab kab shrink karunga window ko
            //jab mera window size> pattern size hojaye

            if(j-i+1>n)
            {
                freq_s[s[i]-'a']--;
                i++;
            }

            if(freq_s == freq_p)
            {
                result.push_back(i);
            } 

            j++;
        }

        return result;
        
    }
};