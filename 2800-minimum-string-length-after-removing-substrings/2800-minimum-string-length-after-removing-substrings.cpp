class Solution {
public:
    int minLength(string s) {
        //jab bhi string ke beech mei characters  remove karne ka question aata hai 
        //toh stack mind mei aana chaiye

        //bas isme fir aasaan hogaya 
        //currrent character and stack ke top wala logic use karlenge

        stack<char> st;

        for(char current_ch: s)
        {
            if(st.empty())
            {
                st.push(current_ch);

            }

            else if(st.top() == 'A' && current_ch == 'B')
            {
                st.pop();
            }
            
            else if(st.top()=='C' && current_ch == 'D')
            {
                st.pop();
            }

            else
            {
                st.push(current_ch);
            }
        }

        return  st.size();
    }
};