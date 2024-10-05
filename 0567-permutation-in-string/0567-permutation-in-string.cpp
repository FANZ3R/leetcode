class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        sort(s1.begin(),s1.end());

        //cout<<s1<<endl;
        string data=s2;

        

        int hop=s1.size();

        for(int i=0;i<data.size();i++)
        {
            if(i+hop<=data.size())
            {
                string temp = data.substr(i,hop);
                sort(temp.begin(),temp.end());
                //cout<<temp<<endl;
                if(temp == s1)
                return true;
            }
        }

        return false;
        
    }
};