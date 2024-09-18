class Solution {
public:
    string largestNumber(vector<int>& nums) {
   
        auto lambda = [](int &x,int &y)
        {
           //dekh cpp mei strings ko agr compare karne jaao toh 
           //character by character compare karta hai unke ascii valuesse
           //for example string 1="91"  and string2="873"
           //but compare karte hue "91" >"873" string format mei coz '9' >'8'
           //aur numerically tera 873>91

           //but dekh agr ek number 30 hai aur dusra 3 hai toh inka first character same hai
           //toh muje large number banana toh fir 0 wala end mei aana chaiye
           //jaise agr 34 aur 33 hota toh 3433 number banskta toh 34 pehle aana chaiye
           //aur jaise 30 aur 3 hai toh 303 banskta hai aur 330 banskta hai but 330 jaada bada hai 
           //isilie mai dono ki strings ko add krke compare kardunga

           string s1 = to_string(x);
           string s2 = to_string(y);

           return(s1+s2>s2+s1); 

          

           

        };

        sort(nums.begin(),nums.end(),lambda);

        //agr sort karne ke baad bhi largest 0 hi aata hai

        if(nums[0]==0)
        return "0";

        string res;

        for(int x:nums)
        {
            res+=to_string(x);
        }

        return res;
        
    }
};