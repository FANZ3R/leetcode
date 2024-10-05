class Solution {
public:
    int maxVowels(string s, int k) {

        //dekh substring mei max number of vowels nikaalne
        //toh jab bhi substring ya subarray aata toh mind pe sbse phle sliding window
        //chamakna chaiye terko

        //ab sliding window lunga aur har window ke lie vowels count karta rahunga

        set<char> st;

        int n=s.size();

        st={'a','e','i','o','u'};

        int ans=0;
        int count =0;
        int i=0;
        int j=0;       

        while(j<n)
        {
            char ch=s[j];

            if(st.find(ch)!=st.end())
            {
                count++;

            }


            if(j-i+1==k)
            {
                ans=max(ans,count);

                if(st.find(s[i])!=st.end())
                {
                    count--;
                }

                i++;
            }

            j++;
        } 

        return ans;
    }
};