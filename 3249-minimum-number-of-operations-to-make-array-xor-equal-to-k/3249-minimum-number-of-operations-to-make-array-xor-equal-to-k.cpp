class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        //pehla poora xor leleeta

        int xor_nums=0;

        for(int num:nums)
        {
            xor_nums^=num;
        }

        //ab agr mai xor lung totla xor ka aur k ka jo desired hai
        //toh jaha pe bhi mera 1 aayega resultant pe waha pe change krne ki jroort hai
        //mtlb final xor emi set bits count karlunga

        int final_xor=xor_nums^k;

        int ans=__builtin_popcount(final_xor);
        return ans;
    }
};