class Solution {
public:


    vector<int> solve(string s)
    {
        vector<int> result;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='+' || s[i]=='*'  || s[i]=='-')
            {
                vector<int> left_results = solve(s.substr(0,i));

                vector<int> right_results = solve(s.substr(i+1));

                for(int &x:left_results)
                {
                    for(int &y:right_results)
                    {
                        if(s[i]=='+')
                        {
                            result.push_back(x+y);
                        }
                        else if(s[i]=='-')
                        {
                            result.push_back(x-y);
                        }
                        else
                        {
                            result.push_back(x*y);
                        }
                    }
                }
            }

            //ab dekh aisa bhi hoskta ki jab mai left string bhejunga toh usme koi operator hji na ho 
            //toh us case mei poori string hi result mei push kardenge integer mei convert karke

        }
        
        if(result.empty())
        {
            result.push_back(stoi(s));
        }

        return result;
    }


    vector<int> diffWaysToCompute(string expression) {
        //dekh mai recursive approach lagaunga aur merpe choice 
        //choice ye hai ki har operator mei mai string ko divide karskta hu left part and right part mei
        //fir left part ko recursively  solve karke uske ans nikaal lnunga aur right part ko solve krke uske ans
        //fir mai left aur right wale ans ke different combination se different ans nikaal lunga

        return solve(expression);
        
    }
};