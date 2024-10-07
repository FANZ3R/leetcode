class Solution {
public:
    int maxConsecutiveAnswers(string a, int k) {

        //isko mai 2 pass of sliding window se banaunga 
        //firstly mai tera maanunga ki mai sirf false ko convert karskta true mei

        int countf=0;
        int i=0;
        int j=0;

        int n=a.size();

        int result=0;

        //first pass F->T
        while(j<n)
        {
            if(a[j]=='F')
            {
                countf++;
            }

            //ab shrink kab karunga window ko jab mera false count >k hoga
            //kyuki mai k tak ke false ko convert karskta true mai

            while(countf>k)
            {
                if(a[i]=='F')
                {
                    countf--;
                }
                i++;
            }

            result = max(result,j-i+1);
            j++;
        }

        //aur similar hi code rahega second pass ke lie
        //second pass T->F

        i=0;
        j=0;
        int countt=0;//count of truths
         while(j<n)
        {
            if(a[j]=='T')
            {
                countt++;
            }

            //ab shrink kab karunga window ko jab mera false count >k hoga
            //kyuki mai k tak ke false ko convert karskta true mai

            while(countt>k)
            {
                if(a[i]=='T')
                {
                    countt--;
                }
                i++;
            }

            result = max(result,j-i+1);
            j++;
        }


        return result;
        
    }
};