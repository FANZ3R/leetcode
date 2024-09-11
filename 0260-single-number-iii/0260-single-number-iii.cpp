class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {


        //dekh mai kya karunga pehle to poora xor nikaallunga theeke
        //fir mai dekhunga ki jo do number hai wo right side se konsi bit mei differ krre
        //toh jo rsulting xor mei jaha pe bhi 1 aaya lsb se start krke 
        //uske basis pe mai saare numbers ko do groups mei divide kardunga

        //divide karne ke lie mai mask use karunga
        //aur mask mai banaunga with first bit from lsb jo ki different hogi dono numbers mei
        // aur baaki sab 0s honge
        //toh ye mask easily we cna make with jo final xor hoga usiko &(- final xor se)


        ///for e.g. final 3 n 5 final xor is 110 so mask will be 010 kese (110) ko &krke(-110) se will give 010
        //3 is 011 and 5 is 101 


        //bas ye yaad rkhna n &(-n) hamei aisa number deta jiski 1st bit 1 hoti in number from lsb rest are zeros

        long long res_xor=0;

        for(int &n:nums)
        {
            res_xor^=n;
        }

        int mask= res_xor &(-res_xor);

        //ab har number ko mask se & krenge taaki pata krske groupa mei daalna ye group b mei

        //toh mai agr 1 aya mask wali bit pe toh A mei daalunga else B mei

        int groupA=0;
        int groupB=0;

        for(int &n:nums)
        {
            if(mask&n)
            {
                groupA^=n;
            }
            else
            {
                groupB^=n;
            }

        }

        return {groupA,groupB};


        //ab divide karne ke baad numbers ko 
        
    }
};