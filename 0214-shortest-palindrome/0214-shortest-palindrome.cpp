class Solution {
public:

    //ye trick wala method hai 0(n^2) jaayega aur memory exceeded dedega par
    //u should know
    //dekh mai sirf front pe append karskta hu apni strign ke 
    // mai isme sabse bada valid palindrome dhundunga reverse ka help lekr
    // toh mai pata kaise lagaunga ki kya add krana hai muje
    // lets take a string "abad" isme muje saaf dikhra hai ki d lagaunga toh aplindrome bnjaayega
    //but isko agr mai dekh reverse karta hu toh aata hai "daba" 
            //                                 n original "abad"
            //phele  mai reverse aur original ko compare karunga nahi hai equal dono
            //ab mai reverse ke starting se move karna start karunga aur original ke peeche se
            //toh starting ke d ko chod dunga aur reverse mei aur original ke peeche se d ko chod dunga
            //toh aba == aba toh mtlb yaha tk shi hai bas muje reverse ka bacha hua string apne original mei append karna hoga

            // toh return rev.substr(0,i)+ s;

            //aur kudx bhi equal nhi ata toh poora hi string add karna padega fir toh
            //toh return rev+s

    string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());

        int n=s.size();

        for(int i=0;i<n;i++)
        {
            // if(s.substr(0,n-i)==rev.substr(i))
            // return rev.substr(0,i)+s;

            //ba dekh ye upar wala code run toh hora hai but submit ni hora kyuki memory limit exceeded dera hai
            //toh isko solve karne ke lie hampe c++ pe hota hai memory comparison ke lie ek option
            //

            //memcmp krke ek utility hota c++ mei jo ye karne nmmei help karega

            //ab isme dekh 3 parameter hote  phla ko kis index se compare krre ,dusre ko kis index se compare krre aur 3rd kitne length tak compare krre
            //toh ye 3 parameters htoe
            //ab m,ai original ko to starting se compare karunga ...uske peeche walo ko ignore karunga
            //aur mai reverse ke ith index se start karunga ..... uske starting walo ko chodna ek ek krke start kaunga
            //aur length comparison ki starign me popoori hogi yaani ki n-i .....aur jaise jaise i badega fir ghat ti jaayegi 

            //aur agr equal aate hai dono string toh memcmp return  0 karta hai

            if(!memcmp(s.c_str(), rev.c_str()+i,n-i))
            {//        prefix     suffix        length comparison ki
                return rev.substr(0,i)+s;
            }

        }

        return rev+s;





       
        
    }
};