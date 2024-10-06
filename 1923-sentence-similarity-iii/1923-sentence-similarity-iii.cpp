class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        //isse pehle waale submission mei maine poora explain kiya  hua
        //usme mai bas vector lera hu aur 4 pointers lene padre usme
        //isme mai agr bas vector ke bdle deque lelunga kyuki pop front se aur back s ebhi krstke
        //aur agr at the end jo smaller wala deque hai wo empty wo hogya mtlb saare words dekhlie 
        //uske aur i can insert another sentence in between then
        
        //i will be assuming s1 is always bigger than s2
        if(s1.size()<s2.size())
        {
            swap(s1,s2);
        }


        deque<string> dq1;
        deque<string> dq2;


        stringstream ss1(s1);
        stringstream ss2(s2);

        string token;

        while(ss1>>token)
        {
            dq1.push_back(token);
        }


        while(ss2>>token)
        {
            dq2.push_back(token);
        }

        while(!dq1.empty() && !dq2.empty() && dq1.front() == dq2.front())
        {
            dq1.pop_front();
            dq2.pop_front();
        }

        while(!dq1.empty() && !dq2.empty() && dq1.back() == dq2.back())
        {
            dq1.pop_back();
            dq2.pop_back();
        }

        //ab agr samller wala dq2 empty hua toh return true
        return dq2.empty();
        
    }
};