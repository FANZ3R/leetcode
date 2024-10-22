class Solution {
public:
//ab isme pruning bhi krskte but apne upr wo

    void solve(string s,int i, unordered_set<string>&st,int currcount,int &maxcount)
    {
        if(i>=s.size())
        {
            maxcount =max(maxcount,currcount);
            return;
        }

        for(int j=i;j<s.size();j++)
        {
            string sub = s.substr(i,j-i+1);
            if(st.find(sub)==st.end())
            {
                st.insert(sub); //DO
                solve(s,j+1,st,currcount+1,maxcount); //EXPLORE

                //ab dekh yaha pe j+1 kyu kar rahei? instead of i+1
                //kyuki j tak ka substring mei lelunga fir muje next jisme split karna wo j+1 se hi milega
                //kyuki maanle maine aba ko split maara ababccc mei toh mera i toh abhi bhi 0 pe hai  but j=2
                //toh next split ke lie bccc bacha jiske lie starting index 3 hai jo ki j+1 se hi aayega
                
                st.erase(sub); //UNDO
            }
        }
    }

    int maxUniqueSplit(string s) {
        //dekh isme choice hai har character pe ki yaha pe split karna hai ki nahi
        //aur pehele dkha ki nahi uske lie set of strings rakh lunga mai
        //but kya pata aage split karne se ajada shi milte toh
        //set of strings uske lie alga aayega
        //iske lie backtracking lagaunga
        //do explore and then undo
        //kyuki string ki length ka constraint bhi kam hai 16 toh lag jaayega ispe


        unordered_set<string> st;

        int currcount=0;
        int maxcount=0;

        int i=0;

        solve(s,i,st,currcount,maxcount);

        return maxcount;
        
    }
};