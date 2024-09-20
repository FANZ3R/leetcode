class Solution {
public:

    void computeLPS(string pattern,vector<int> &LPS)
    {
        int m=pattern.size();
        LPS[0]=0;
        int length=0;

        int i=1;

        while(i<m)
        {
            if(pattern[i]==pattern[length])
            {
                length++;
                LPS[i]=length;
                i++;
            }
            else
            {
                if(length!=0)
                {
                    length=LPS[length-1];
                }
                else
                {
                    LPS[i]=0;
                    i++;
                }
            }
        }

    }


    string shortestPalindrome(string s) {

        //ab dekh isko mai kmp wale algorithm ke lps weaale code se karskta 
        //dekh agr mei reverse kardu apni given string ko 
        //aur fir muje apni original string ka longest common prefix nikaalna hai jo equal hai suffix ke in reverse
        //thoda pecheeda laga hoga sunke

        //dekh example le 
        //"abad" original   reverse "daba"  ab dekh isme longest common prefix which is equal to suffix in reverse hai tera
        // aba  theeke ye hai valid longest proper prefix jo equal haio suffix ke in reverse
        //mtlb ye valid palindrome hai...m tlb ye part reverse ka valid hai apne original mei

        //toh bacha hua part kya hai reverse ka "d" after removing lps "aba"
        //toh agr mei ye d laga du apne original mei "dabad" toh bngya shortest palindrome 

        //toh bas muje lps nikaalna hai ..par lps mei ek hi string jaati hai function mei 
        //toh mai original ko append kardunga with reverse with '#' as separator
        //theeke fir lps largest hamesa n-1 pe hota jaaha n pattern ka length hota

        //toh bas remaining culprit jo string ka hoga wo hoga reverse ka starting se to length n-(lps[n-1])
        //kyuki lps[n-1] length ka toh originally present hai baaki n-(lps[n-1]) add karna hoga

        string rev=s;
        reverse(rev.begin(),rev.end());

        

        string pattern= s+"#"+rev;
        //append kardunga with # as separator
        //ab bas muje iska ps nikaalna hai

        vector<int> LPS(pattern.size(),0);

        computeLPS(pattern,LPS);
        //ek hi string jaati hai LPS function mei

        //ab mera LPS bangya 
        int x=LPS.size();
        int lengthoflongest_LPS=LPS[x-1];

        //ab itna length equal hai merpe baaki n-lengthoflongest_LPS muje reverse ka starting se add karna hoga apne original mei

        int n=rev.size();
        string culprit= rev.substr(0,(n-lengthoflongest_LPS));

        return culprit+s;
        
    }
};