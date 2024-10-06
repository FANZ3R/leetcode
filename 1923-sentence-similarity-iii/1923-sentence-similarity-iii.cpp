class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {

        //tohn dekh mai assume karraha hu ki sentence 1 hi hamesa bada hoga sentence 2 se
        //kyuki isme koi bhi bada hoskta aur chote waale ko check karna haio ki
        //toh agr sentence 2 bada toh swap karlunga
        //ye itna imp nhi


        //ab imp lopgical part
        //theeke mai 4 pointer loonga 2 string1 ke lie ek starting index ke lie aur ek ending 
        //ab chote wale string mtlb string 2 ke pointer l and k hogne
        //agr phle toh startign jitne words same aaye mai k ko badhate rahunga
        //aur fir auske baad jitne se peeche se same aaye mai l ko ghatata rhunga
        //agr at the end mera l<k hojaaye mtlb maine saare words dekh liye string 2 ke in string 1 in order
        //aur yaha pe ek sentence daala ja skta toh return true kardunga

        if(s2.size()>s1.size())
        {
            swap(s1,s2);
        }


        //pehle toh inko words mei split kardeta hu using stringstream

        vector<string> v1;
        vector<string> v2;

        stringstream ss1(s1);
        string token;

        while(ss1>>token)
        {
            v1.push_back(token);
        }

        stringstream ss2(s2);
        
        while(ss2>>token)
        {
            v2.push_back(token);
        }

        //ab words by words split hogye dono

        //ab 4 pointers loonga
        int i = 0, j = v1.size()-1;///ye badi waali strign ke lie s1
        int k = 0, l = v2.size()-1;//ye stirng s2 ke lie 

        while(i<v1.size() && k<v2.size() && v1[i]==v2[k])
        {
            //jabtak dono ke words same honge pointers ko badhata rhunga
            i++;
            k++;
        }

        while(l>=k && v1[j]==v2[l])
        {
            j--;
            l--;
        }

        //agr at the end mera l pointer <k pointer hua toh yes sentence daal skta mai 
        return l<k;



        
    }
};