/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
      //dekh meri value 1 se n ke beech me hi hai
      //ab abdi hai ya choti wo muje guess function dedegea
      //toh mai har value try karlunga aur fir kis trf hai uske lie 
      //mai binary search laga lunga dekhne ke lie ...kidr mera number hoga

        int l=1;
        int r=n;

        while(l<=r)
        {
            int mid = l+(r-l)/2;//mera guess abhi ye hai 
            //mai ispe search karra hu

            int val=guess(mid);//ye muje 0,-1,ya 1 dega based on my guess

            if(val==0)
            return mid;

            else if(val==1)//guess lower hai target se
            {
                l=mid+1;
            }
            else 
            {
                r=mid-1;
            }
        }

        //kyuki suire hai upr fuinction se return aayega hi 
        //toh yaha dummy return daal denge
        return -1;


        
    }
};