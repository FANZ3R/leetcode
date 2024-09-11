class Solution {
public:
    int minFlips(int a, int b, int c) {

        //mia general mehtod nahi lagaskta isme
        //muje har bit ko check karke hi karna hoga
        //do hi case jab c ki right most bit 1 hai agr 
        //toh muje koi bhi 1 chlaegei
        //bas muje tb flip krne ki necessity hogi jab dono 0 honge is case mei

        // aur jab right most c ki 0 hogi
        //toh dono ko 0 hona necessary hai agr nhi hai toh dono ko flip karna padega

        int count =0;

        while(a || b || c)
        {
            if((c&1)==1)//agr rightmostbit in c is 1
            {
                //toh koi bhi 1 chalega bas agr dono zero hai to kisi ek ko flip kardo
                if((a&1)==0 &&(b&1)==0)
                    count++;
            }
            else        //rightmost bit in c is 0
            {
                //toh is case mei dono ka 0 hona necessary hai
                if((a&1)==1)  count++;
                if((b&1)==1)  count++;
            }

            // har check ke baad har ek ko right shift karta jaunga

            a=a>>1;
            b=b>>1;
            c=c>>1;
        } 

        return count;
        
    }
};