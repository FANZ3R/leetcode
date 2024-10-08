class Solution {
public:
    int minSwaps(string s) {
        //dekh agr mai balance pairs ko hatadu 
        //toh mera input hamesa kux aise hi pattern mei rahega
        /// ]]] [[[   hamesa ye hi pattern mei hoga
        //ab ek swap se mere do pair of parenthesis balance hore
        //upar wale example mei hi dekhle if i swap index 1 with 4 toh ek swap se 2 pair (1,3) & (4,5) balance ho jyege

        //toh mai kya stack lelunga agr [ dikha toh push krdunga stack mei aur agr ] dikha aur stack empty nhi hai 
        //toh pop karta rhunga aur fir at the end stack ke size ke basis pe 
        //ab dekh ek swap se 2 balance honge toh stack ke size /2 swaps necessary
        //but agr stack ka size odd hua toh uske lie +1 krna pdega
        //toh i will retun (stack.size()+1)/2  at the end

        stack<char> st;

        for(char &ch: s)
        {
            if(ch=='[')
            {
                st.push(ch);

            }
            else if(!st.empty())
            {
                st.pop();
            }
        }

        //aur at the end swaps required = (st.size()+1)/2;
        return (st.size()+1)/2;        
    }
};