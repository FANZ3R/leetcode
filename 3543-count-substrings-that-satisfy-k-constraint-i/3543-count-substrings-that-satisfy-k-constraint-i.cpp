class Solution {
public:
    //previous wala submission toh iska brute force tha
    //but ye substring ya subarray jkab bhi aaye toh dimaag mei sliding window aana chaiye
    //ab isko bhi sliding window ke approach se bana skta 
    //aur ek window mei valiud string s hogne tere j-i+1 mtlb poor awindow size

    //ab sldiing window mei muje shrinking condition chaiye hota
    //toh iska shrinking condition hoga if count_0>k && count_1>k

    //&& kyu kyuki agr ek bhi satisfy hora to tb bhi bhi valid hoga
    //toh invalid hoine k elie dono ko unsatisfy karna hai

    int countKConstraintSubstrings(string s, int k) {

        int i=0;
        int j=0;

        int count_0=0;
        int count_1=0;

        int n=s.size();


        int substrings=0;
        while(j<n)
        {
            if(s[j]=='0')
            {
                count_0++;
            }
            else
            {
                count_1++;
            }

            //ab tera shrinking condition hoga

            while(count_0 > k && count_1 > k)
            {
                if(s[i]=='0')
                count_0--;

                else
                count_1--;

                i++;
            }

            substrings+=(j-i+1);
            j++;
        }

        return substrings;
        
    }
};