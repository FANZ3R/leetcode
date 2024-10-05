class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        sort(s1.begin(),s1.end());

        //cout<<s1<<endl;
        string data=s2;

        int n=s1.size();
        int m=s2.size();

        

        int hop=s1.size();

        for(int i=0;i<=m-n;i++)
        {
            
                string temp = data.substr(i,hop);
                sort(temp.begin(),temp.end());
                //cout<<temp<<endl;
                if(temp == s1)
                return true;
            
        }

        return false;
        
    }
};