class Solution {
public:

    void solve(string s,unordered_set<string> &st, int i,int currcount,int &maxcount)
    {
        if(i == s.size())
        {
            maxcount = max(currcount , maxcount);
            return ;
        }

        for(int j=i;j<s.size();j++)
        {
            string sub = s.substr(i,j-i+1);

            if(st.find(sub) == st.end())
            {
                //do 
                st.insert(sub);

                //explore
                solve(s,st,j+1,currcount+1,maxcount);

                //undo
                st.erase(sub);
            }
        }
    }


    int maxUniqueSplit(string s) {

        unordered_set<string> st;

        int currcount = 0;
        int maxcount = 0;
        int i=0;

        solve(s,st,i,currcount,maxcount);

        return maxcount;

        
    }
};