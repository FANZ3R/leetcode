class Solution {
public:

    void solve(string s,int i, unordered_set<string>&st,int currcount,int &maxcount)
    {
              //ab isme pruning bhi daaal skta
        //kyuki agr isi bhi index pe hu toh uske baad max unique string kitne mil skte jitne character hone
        //wo max tabhi milenge jab teeno unique characters honge

        //but max utne hi milskte 

        // toh

        if(currcount + s.size()-i < maxcount)
        return ; 


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