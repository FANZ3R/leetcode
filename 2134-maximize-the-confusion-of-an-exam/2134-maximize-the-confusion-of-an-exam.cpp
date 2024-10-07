class Solution {
public:
    int maxConsecutiveAnswers(string a, int k) {

        // can be done using 2 pass sliding window
        int n=a.size();

        int i=0;
        int j=0;

        
        int countF=0;
        int result=0;


        //first time i will convert all F to T
       while(j<n)
       {
        if(a[j]=='F')
        {
            countF++;
        }

        while(countF>k)
        {
            if(a[i]=='F')
            {
                countF--;
            }

            i++;

        }
        result=max(result,j-i+1);
        j++;
       }

       //int the second pass of sliding window i will convert all F to T

       i=0;
       j=0;

       int countT=0;

       //T->F
       while(j<n)
       {
        if(a[j]=='T')
        {
            countT++;
        }

        while(countT>k)
        {
            if(a[i]=='T')
            countT--;

            i++;
        }

        result=max(result,j-i+1);
        j++;


       }



       return result;

        
    }
};