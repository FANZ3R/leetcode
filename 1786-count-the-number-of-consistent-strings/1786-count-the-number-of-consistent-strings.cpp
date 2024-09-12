class Solution {
public:

    bool check (unordered_set<char> &st,string &word)
    {
        for(char ch:word)
        {
            if(st.find(ch)==st.end())
            return false;//agr nhi mila character toh
        }

        return true;


    }
    int countConsistentStrings(string allowed, vector<string>& words) {

        unordered_set<char> st;

        for(char ch:allowed)
        {
            st.insert(ch);
        }

        int count =0;
        for(string x: words)
        {
            if(check (st,x))
            count++;
        }
        return count;
        
    }
};