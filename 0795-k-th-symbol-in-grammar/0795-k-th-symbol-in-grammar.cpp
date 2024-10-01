class Solution {
public:
  //toh dekh i cannot build string for every row here
  //as it will give mle and tle
  //toh muje ovserve karna hai har row
  //toh dekh every row ka first is equal to previous row
  //toh mai is row ko do half me divide karke observe karunga
  //agr mera k first half mei hai to mai diorect n-1 row mei jaake uska kth element nikala lunga
  //aur observe kar ki jo second half hai nth row wo complement hai n-1th row ka
  //toh agr second half mei aayega k i will simply return complement of k-mid element of n-1 row

    int kthGrammar(int n, int k) {
        if(n==1)
        return 0;

        int length= pow(2,n-1);
        //represents length of each row
        int mid= length/2;

        if(k<=mid)//agr first half mei aata hai toh
        return kthGrammar(n-1,k);

        //else mai n-1 row ka k-mid element ka complement return kardunga
        return !kthGrammar(n-1,k-mid);
        //dhyan se dekh "!" lagaya hai complement ke lie
        

      
    }
};