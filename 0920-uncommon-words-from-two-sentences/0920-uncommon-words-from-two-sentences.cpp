class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {

        unordered_map<string ,int> mp1;
        unordered_map<string,int> mp2;

        int pos=0;

        for(int i=0;i<s1.size();i++)
        {
            if(s1[i] == ' ')
            {
                string s =s1.substr(pos,i-pos);
                mp1[s]++;
                pos=i+1;
            }
            
        }
        
        //end word bhi push kar denge

        string endword1=s1.substr(pos,s1.size()-pos);
        mp1[endword1]++;


        //ab ye hi dusri string ke lie karenge

        pos=0;

        for(int i=0;i<s2.size();i++)
        {
            if(s2[i]==' ')
            {
                string s =s2.substr(pos,i-pos); //substring mei starting index jaata aur dusra parameter size hota string ka
                mp2[s]++;
                pos=i+1;
            }
            
        }
        
        //end word bhi push kar denge

        string endword2=s2.substr(pos,s2.size()-pos);
        mp2[endword2]++;

        vector<string> ans;

        for(auto t:mp1)
        {
            string word=t.first;

            if(mp2.find(word)==mp2.end() && mp1[word]==1)
            {
                ans.push_back(word);

            }
        }

        for(auto t:mp2)
        {
            string word=t.first;
            
            if(mp1.find(word)==mp1.end()  &&  mp2[word]==1)
            {
                ans.push_back(word);
            }
        }

        return ans;

        
        
    }
};