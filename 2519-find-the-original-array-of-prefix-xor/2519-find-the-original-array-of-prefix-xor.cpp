class Solution {
public:
    vector<int> findArray(vector<int>& pref) {

        //question ko danghse dekh pehle observe kar

        //agar mera desired array a0,a1,a2,a3,a4 hota
        // toh for first exmaple 5=a0
                            //  2=a0^a1
                            //  0=a0^a1^a2
                            //  3=a0^a1^a2^a3
                            //  1=a0^a1^a2^a3^a4

                            //ab observe kar isme ki agr mai last 2 equations ko xor kardu toh iwill get a4
                            //3^1 =a4

                            // toh genralising ai=pi^pi-1
        int n=pref.size();
        vector<int> ans(n,0);

        ans[0]=pref[0];

        for(int i=n-1;i>=1;i--)
        {
            ans[i]=pref[i]^pref[i-1];
        }

        return ans;
        
    }
};