class Solution {
public:
    bool parseBoolExpr(string exp) {

        stack<char> st;

        //toh dekhg  mai stack mei push karunga dono operator and boolean values
        //comma ;aur opening parenthiesis pe iongnoree kar dunga
        //aur closing parenthesis pe mai expression ko evaluate karung ajab tk operator na dikh jaaye


        for(char ch: exp)
        {
            if(ch == ',' || ch =='(')
            continue;
            //toh ignore maarna 

            else if(ch == '!' || ch == '&' || ch =='|' || ch=='t' || ch=='f')
            {
                st.push(ch);
            }

            else if(ch == ')')
            {
                //toh mai do bool banaunga check karne ke lie ki true ya false haio meri is current expression mei

                bool hastrue = false;
                bool hasfalse = false;

                //ab expression ko evaluate karungga jab tk muje operator nahi miljaata

                while(st.top()!= '!' && st.top() != '&' && st.top() != '|')
                {
                    char top =st.top();
                    st.pop();

                    if(top=='t')
                    hastrue =true;

                    else if(top =='f')
                    hasfalse=true;

                }

                //ab bnreak hoga jab operator milega
                char op =st.top();
                st.pop();

                if(op=='!')
                {
                    if(hastrue == true)
                    {
                        st.push('f');
                    }
                    else
                    {
                        st.push('t');
                    }
                }

                else if(op=='&')
                {
                    if(hasfalse == true)
                    {
                        st.push('f');
                    }
                    else
                    {
                        st.push('t');
                    }
                }

                else if(op=='|')
                {
                    if(hastrue==true)
                    {
                        st.push('t');
                    }
                    else
                    {
                        st.push('f');
                    }

                }
            }
        }

        cout<<st.top();
        //muje boolean return karna naaki f
        return st.top() == 't';


        
    }
};