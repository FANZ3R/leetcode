class Solution {
public:
    int minFlips(int a, int b, int c) {

        int result = ((a|b)^c);//flips

        //??isme ek cheez missing hai jab dono a and b ki bits 1 hongi
        //a&b

        int result1 =  (a&b);

        int result2 = (result1 & result);

        return __builtin_popcount(result) + __builtin_popcount(result2);


        
    }
};