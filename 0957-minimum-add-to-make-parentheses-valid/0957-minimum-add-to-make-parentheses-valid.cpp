class Solution {
public:
    int minAddToMakeValid(string s) {

        //balance kardunga paranthesis ko using stack 
        //( push karunga stack mei aur agr empty nahi hai toh pop karunga 
        //at the end stack ke size answer ajaeyga

        stack<char> st;

        int count =0;

        for(char &ch: s)
        {
            if(ch=='(')
            {
                st.push(ch);
            }
            else if(!st.empty())
            {
                st.pop();
            }
            else if(ch==')'  && st.empty())
            {
                count++;
            }
        }

        return st.size()+count;
        
    }
};