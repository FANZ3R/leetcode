class Solution {
public:

    //dekh merpe har character pe choice hai ki ya toh mai use extra character 
    //ke trah treat karu ya fir mai use aage potential match ke lie jaane du
    //agr extra char maanta hu toh mai 1 extra character add karke baaki aage ke lie solve kardunga
    //aur yadi aage match hota hai toh mai 0 add karke baaki aage ke lie check kar dunga
    //aur fir minimum find karlunga jaha se bhi mile mujhe
    // toh mai ye recursively karskta 

    //aur ez comparison ka dictiorary se usko set mei daaldunga

    int n;

    int t[51];
    //diya hai 50 length hai max string ka
    int solve(int idx, string &s, unordered_set<string>& st)
    {
        if(idx>=n)
        return 0;


        if(t[idx]!=-1)
        return t[idx];

        //ab agr mai use extra character maanta hu
        //toh

        int result =  1 + solve(idx+1,s,st);

        //ab potentioal match ka check karunga
        //aur har character pe jaake ye hi repeat karna hai muje

        for(int j=idx;j<n;j++)
        {
            string curr=s.substr(idx,j-idx+1);

            if(st.find(curr)!=st.end())
            {
                //toh mtlb valid string hai
                //toh minimise karenge result ko

                result=min(result,solve(j+1,s,st));
            }

        }

        return t[idx]= result;
    }

    int minExtraChar(string s, vector<string>& dictionary) {

        memset(t,-1,sizeof(t));

        n=s.size();

        unordered_set<string> st(dictionary.begin(),dictionary.end());

        return solve(0,s,st);
        
    }
};