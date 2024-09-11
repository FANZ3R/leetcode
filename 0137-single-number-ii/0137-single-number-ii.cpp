class Solution {
public:
    int singleNumber(vector<int>& nums) {
        

        //standard approach this works best for both single number 1 and single number 2

        //32 bit ka number derakha hai most
        //so ham har bit [e kaayenge 32] aur bit pe jaake 
        //har numebr ke we will count no of 1 bit and 0 bit
        //agr countof1's %3==1 hota hai toh mtlb hamare target number pe is bit pe 1 hai

        //toh ham har bit ka nikaal nikaal kr OR karte rahnege at the end

        int result=0;

        for(int i=0;i<=31;i++)
        {
            int temp=1<<i;//1 ko left shift karunga i se har ith bit nikaalne ko

            int countZeros=0;
            int countOnes=0;

            for(int &num : nums)
            {
                if((num & temp)==0)
                {
                    countZeros++;
                }
                else
                {
                    countOnes++;
                }
            }

            //ab saare count pata chlgya agr mod lene pe 3 se 1 ata to mtlb target number ke ith bit pe 1 hai
            if(countOnes%3==1)
            {
                result=result | temp;
                //toh ham wo waali bit OR kardenge apne result mei
                //aise karte jayenge jab pata chalega resulting number pe yha pe 1 hai
            }
        }

        return result;
    }
};